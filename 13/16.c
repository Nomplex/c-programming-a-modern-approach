#include <stdio.h>

#define MAX 30

void reverse(char *message);

int main(void)
{
	char message[MAX+1], *p = message, ch;

	printf("Enter a message: ");
	while (p < message + MAX && (ch = getchar()) != '\n')
		*p++ = ch;
	*p = '\0';

	reverse(message);

	printf("Reversal is: %s\n", message);

	return 0;
}

void reverse(char *message)
{
	char *p = message, *q = message, temp;

	while (*q)
		q++;
	q--;

	while (p < q) {
		temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}

}
