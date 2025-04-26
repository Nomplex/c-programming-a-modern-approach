#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 30

int main(void)
{
	bool palindrome = true;
	char message[MAX], ch, *len = message;

	while (len < message + MAX && (ch = getchar()) != '\n')
		if (isalpha(ch))
			*len++ = toupper(ch);
	len--;

	for (char *p = message; p < len; p++, len--)
		if (*p != *len) {
			palindrome = false;
			break;
		}

	if (palindrome)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}
