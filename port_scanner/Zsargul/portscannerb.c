#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.g>

int main(int argc, char *argv[]) {
	
	int start, end, i, conn, sock;
	char hostname[50];
	char startStr[6];
	char endStr[6];

	struct hostent *host;
	struct sockaddr_in sockAddress;

	printf("Enter targets IP address or hostname:\n");
	fgets(hostname, 50, stdin);
	// Protect against fgets overflow
	if (hostname[strlen(hostname)-1] != '\n') {
		for (int c; (c = getchar()) != EOF && c != '\n';);
	}

	printf("Enter starting port:\n");
	fgets(startStr, 6, stdin);
	if (startStr[strlen(startStr)-1] != '\n') {
		for (int c; (c = getchar()) != EOF && c != '\n';);
	}
	start = atoi(startStr);

	printf("Enter ending port:\n");
	fgets(endStr, 6, stdin);
	if (endStr[strlen(endStr)-1] != '\n') {
		for (int c; (c = getchar()) != EOF && c != '\n';);
	}
	end = atoi(endStr);
	
	// Initialise sockaddr_in struct
	sockAddress = {0};
	sockAddress.sin_family = AF_INET;

	if (isdigit(hostname[0])) {
		sockAddress.sin_addr.s_addr = inet_addr(hostname);
	} else if ( !(host = gethostbyname(hostname)) ) { // Resolve hostname to IP address
		// strncpy( (char*)&sockAddress.sin_addr, host->h_addr, sizeof(sockAddress.sin_addr) );
		&sockAddress.sin_addr.s_addr = host->h_addr;
	} else {
		herror(hostname);
		exit(2);
	}

	// Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("\nSocket creation error");
		exit(1);
	}

	// Start port scan
	for (i = start; i <= end; i++) {
		sockAddress.sin_port = i;
		
		conn = connect(sock, (struct sockaddr*)&sockAddress, sizeof(sockAddress));
		
		// Connection failed
		if (conn < 0) {
			printf("%s %-5d %s\r", hostname, i, strerror(errno));
			fflush(stdout);
		} else {
			printf("%-5d open\n", i);
		}
		close(sock);
	}

	return(0);

	}
}
