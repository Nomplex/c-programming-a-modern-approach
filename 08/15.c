#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char message[80];
	int size = 0, shift;

	printf("Enter message to be encrypted: ");
	while((message[size++] = getchar()) != '\n');

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	printf("Encrypted Message: ");
	for (int i = 0; i < size; i++) {
		if (message[i] >= 'A' && message[i] <= 'Z')
			putchar((message[i] - 'A' + shift) % 26 + 'A');
		else if (message[i] >= 'a' && message[i] <= 'z')
			putchar((message[i] - 'a' + shift) % 26 + 'a');
		else
			putchar(message[i]);
	}

	return 0;
}
