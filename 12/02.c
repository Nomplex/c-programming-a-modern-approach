#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 30

int main(void)
{
	bool palindrome = true;
	char message[MAX], ch;
	int len = 0;

	while (len < MAX && (ch = getchar()) != '\n')
		if (isalpha(ch))
			*(message + len++) = toupper(ch);

	for (char *p = message, *q = message + len - 1; p <= q; p++, q--)
		if (*p != *q) {
			palindrome = false;
			break;
		}

	if (palindrome)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}
