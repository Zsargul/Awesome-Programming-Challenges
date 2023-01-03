#include <iostream>
#include <string>
#include <cstdlib>

int getLetterPos(char ch, const char alphabet[26]);
bool isInt(char number[]);

int main(int argc, char *argv[]) {
	int shift;

	const char alphabet[26] = { 
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
		'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z'
	};

	const char nums[10] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
	};
	
}

int getLetterPos(char ch, const char alphabet[26]) {
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == ch) {
			return i;
		}
	}
	return -1;
}

bool isInt(char *number) {
	if (*number == '-')
		return false;
	
	while (*number != '\0') {
		if (!isdigit(*number++)) {
			return false;	
		}
	}
	return true;
}
