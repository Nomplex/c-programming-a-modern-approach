
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char name[20], ch, f;
	int size = 0;
	
	printf("Enter a first and last name: ");
	while ((ch = getchar()) == ' ')
		;

	f = ch;
	while ((ch = getchar() != ' '))
		;

	printf("%c", ch);
	while ((ch = getchar()) != '\n') {
		if (ch != ' ')
			name[size++] = ch;
	}

	name[size++] = ',';
	name[size++] = ' ';
	name[size++] = f;
	name[size++] = '.';

	printf("You entered the name: ");
	for (int i = 0; i < size; i++)
		putchar(name[i]);
	putchar('\n');

	return 0;
}
