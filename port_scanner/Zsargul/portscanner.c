/* Simple portscanner written in C
 *
 * Works on linux, untested on windows. Won't scan any ports from addresses
 * blocked in your hosts file
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

int resolve(char *name, struct sockaddr_in *server, char *addrStr); 

int main(int argc, char *argv[]) {
	
	int input, start, end, i, sock, conn, sel, timeout;
	int portc, openc;
	short ipProvided = 0; // Used to check if target was given in IP or hostname form (ex. 74.125.193.138 or "google.com")
	char hostname[50];
	char timeoutStr[4];
	char startStr[6];
	char endStr[6];
	char ipString[50];

	struct sockaddr_in server;
	struct timeval tv;

	// Initialise sockaddr_in struct
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;

	// User Input Section
	printf("Enter targets IP address or hostname:\n");
	fgets(hostname, 50, stdin);
	if (hostname[strlen(hostname)-1] != '\n') { // Protect against fgets overflow
		for (int c; (c = getchar()) != EOF && c != '\n';);
	}


	// Trim newlines to prevent printing and resolving problems
	if (hostname[strlen(hostname)-1] == '\n')
		hostname[strlen(hostname)-1] = '\0';

	// Use IP or resolve hostname to IP address
	if (inet_addr(hostname) != -1) {
		ipProvided = 1;
		server.sin_addr.s_addr = inet_addr(hostname);
		printf("Address provided in IP notation. No resolving needed.\n");
	} else {
		// Resolving host name to IP
		if (resolve(hostname, &server, ipString) != 0) {
			// Unable to resolve hostname
			exit(1); 
		 } else {
		 	server.sin_addr.s_addr = inet_addr(ipString);
		 }
	}

	input = 0;
	while (!input) {
		printf("Enter starting port:\n");
		fgets(startStr, 6, stdin);
		if (startStr[strlen(startStr)-1] != '\n') {
			for (int c; (c = getchar()) != EOF && c != '\n';);
		}
		if ((start = atoi(startStr)) == 0) {
			printf("ERROR: Invalid input\n");
			exit(1);
		}

		if (start <= 0 || start > 65535) {
			printf("ERROR: Please enter a valid port number (0-65535)\n");			
		} else {
			input = 1;
		}
	}

	input = 0;
	while (!input) {
		printf("Enter ending port:\n");
		fgets(endStr, 6, stdin);
		if (endStr[strlen(endStr)-1] != '\n') {
			for (int c; (c = getchar()) != EOF && c != '\n';);
		}
		if ((end = atoi(endStr)) == 0) {
			printf("ERROR: Invalid input\n");
			exit(1);
		}

		if (end <= 0 || end > 65535) {
			printf("ERROR: Please enter a valid port number (0-65535)\n");			
		} else if (end < start) {
			printf("ERROR: Please enter a port larger than the starting port (%d)\n", start);
		} else {
			input = 1;
		}
	}

	input = 0;
	while (!input) {
		printf("Enter connection timeout in seconds (Default: 5, Min: 2, Max: 30)\n");
		fgets(timeoutStr, 4, stdin);
		if (timeoutStr[strlen(timeoutStr)-1] != '\n') {
			for (int c; (c = getchar()) != EOF && c != '\n';);
		}
		if ((timeout = atoi(timeoutStr)) == 0) {
			printf("Timeout remains at default 5\n");
			timeout = 5;	
		}

		if (timeout < 2) {
			printf("ERROR: The timeout must be a minimum of 2 seconds\n");
		} else if (timeout > 30) {
			printf("ERROR: The timeout cannot be larger than 30 seconds\n");
		} else {
			input = 1;
		}
	}

	// Time newlines again
	if (startStr[strlen(startStr)-1] == '\n')
		startStr[strlen(startStr)-1] = '\0';

	if (endStr[strlen(endStr)-1] == '\n')
		endStr[strlen(endStr)-1] = '\0';

	// Messaging summarising scan initiation
	inet_ntop(AF_INET, &server.sin_addr.s_addr, ipString, 50);
	printf("Scanning port");
	if (end == start) {
		printf(" %s ", startStr);
	} else {
		printf("s %s-%s ", startStr, endStr);
	}
	printf("on IPv4 address %s", ipString);
	if (ipProvided != 1) {
		printf(" (%s)", hostname);
	}
	puts(":");

	portc = (end-start)+1;
	openc = 0;
	// Start port scan
	for (i = start; i <= end; i++) {
		printf("%d: ", i);
		fflush(stdout);

		server.sin_port = htons(i);
		sock = socket(AF_INET, SOCK_STREAM, 0);
		fcntl(sock, F_SETFL, O_NONBLOCK);

		if (sock < 0) {
			perror("Error: Unable to create socket");
			exit(1);
		}

		fd_set write_fds;
		FD_ZERO(&write_fds);
		FD_SET(sock, &write_fds);
		tv.tv_sec = timeout; 
		tv.tv_usec = 0;

		conn = connect(sock, (struct sockaddr*)&server, sizeof(server));

		printf("Connecting..."); // 13 chars
		fflush(stdout);

		if (conn < 0 && errno != EINPROGRESS) { // Connection ran into error
			fprintf(stderr, "\r%d: Connection error in connect(): %d (%s)\n", i, errno, strerror(errno));
		} else if (conn == 0) { // Connection succeeded immediately
			printf("\r%d: Open         \n", i);
			openc++;
			fflush(stdout);
		} else { // Connection attempt is in progress
			int sock_sel = select(sock+1, NULL, &write_fds, NULL, &tv);

			if (sock_sel < 0) { // Socket connection error
				fprintf(stderr, "\r%d: Error in select(): %d (%s)\n", i, errno, strerror(errno));
			} else if (sock_sel == 0) { // Socket hits timeout
				fprintf(stderr, "\r%d: Closed (Timeout)\n", i);
			} else if (sock_sel > 0) { // Socket connection in progress
				int so_error;
				socklen_t len = sizeof(so_error);
		
				if (getsockopt(sock, SOL_SOCKET, SO_ERROR, &so_error, &len) < 0) {
					fprintf(stderr, "%d: Error in getsockopt(): %d (%s)\n", i, errno, strerror(errno));
				}

				if (so_error != 0) {
					printf("\r%d: Closed (%s)   \n", i, strerror(so_error));
				} else { // Try connect again
					int conn2 = connect(sock, (struct sockaddr*)&server, sizeof(server));
					if (conn2 == 0) {
						printf("\r%d: Open         \n", i);
						openc++;
					} else {
						fprintf(stderr, "\r%d: Closed (Timeout)\n", i);	
					}
				}
			}
		}
		close(sock);
	}
	printf("Finished scanning. %d of %d ports open\n", openc, portc);
	return(0);
}

int resolve(char *name, struct sockaddr_in *server, char *addrStr) {
	struct addrinfo hints, *res, *result;
	int err;
	
	// Initialise hints
	memset(&hints, 0, sizeof(hints));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_family = AF_INET;
	hints.ai_flags |= AI_CANONNAME;
	
	printf("Resolving %s...\n", name);

	// Try resolve hostname
	err = getaddrinfo(name, NULL, &hints, &result);
	if (err != 0) {
		fprintf(stderr, "Unable to resolve hostname: %s\n", name);
		return 1;
	}

	res = result;

	// Convert resolved IP to string
	inet_ntop(res->ai_family, &((struct sockaddr_in *) res->ai_addr)->sin_addr, addrStr, 50);
	printf("\"%s\" resolved to IPv4 address %s (%s)\n", name, addrStr, res->ai_canonname);

	freeaddrinfo(result);
	return 0;
}
