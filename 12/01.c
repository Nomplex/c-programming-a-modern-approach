#include <stdio.h>

#define MAX 30

int main(void)
{
	char message[MAX], ch;
	int len = 0;

	printf("Enter a message: ");
	while (len < MAX && (ch = getchar()) != '\n')
		message[len++] = ch;

	printf("Reversal is: ");
	for (char *p = message + len - 1; p >= message; p--)
		printf("%c", *p);

	return 0;
}
