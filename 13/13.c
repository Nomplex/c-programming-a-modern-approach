#include <ctype.h>
#include <stdio.h>

void encrypt(char *message, int shift);

int main(void)
{
	char message[80+1];
	int shift;

	printf("Enter message to be encrypted: ");
	fgets(message, 80, stdin);

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	encrypt(message, shift);

	printf("Encrypted Message: %s", message);
	return 0;
}

void encrypt(char *message, int shift)
{
	while (*message) {
		if (*message >= 'A' && *message <= 'Z')
			*message = (*message - 'A' + shift) % 26 + 'A';
		else if (*message >= 'a' && *message <= 'z')
			*message = (*message - 'a' + shift) % 26 + 'a';
		message++;
	}
}
