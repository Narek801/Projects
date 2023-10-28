#include <stdio.h>
#include <string.h>

void main() {
	char password[20];
	int upperChars = 0;
	int lowerChars = 0;
	int numbers = 0;
	int specialChars = 0;
	
	printf("Please enter password: ");
	scanf("%s", password);

	int length = strlen(password);

	if (length < 6) {
		printf("\nPassword must be at least 6 characters long!\n");
		return;
	} 
	for (int i = 0; i < length; ++i) {
		if (password[i] >= 'A' && password[i] <= 'Z') {
			++upperChars;
		} else if (password[i] >= 'a' && password[i] <= 'z') {
			++lowerChars;
		} else if (password[i] >= '0' && password[i] <= '9') {
			++numbers;
		} else {
			++specialChars;
		}
	}

	if (upperChars == 0) {
		printf("Password must contain at least one uppercase character!\n");
		return;
	} 
	if (lowerChars == 0) {
		printf("Password must contain at lease one lowercase character!\n");
		return;
	}
	if (numbers == 0) {
		printf("Password must contain at least one number!\n");
		return;
	}
	if (specialChars == 0) {
		printf("Paswword must contain at least one special character!\n");
		return;
	}
	printf("The strength of password is strong.\n"); 
}