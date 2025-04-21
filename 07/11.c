#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch, f;
	while ((ch = getchar()) == ' ')
		;

	f = ch;
	while ((ch = getchar() != ' '))
		;

	printf("%c", ch);
	while ((ch = getchar()) != '\n') {
		if (ch != ' ')
			printf("%c", ch);
	}

	printf(", %c.\n", f);
	return 0;
}
