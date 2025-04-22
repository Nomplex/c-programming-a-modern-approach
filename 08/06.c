#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch, m[60];
	int size = 0;

	printf("Enter message: ");
	while((ch = getchar()) != '\n' && size < 60)
		m[size++] = ch;

	printf("In B1FF-speak: ");
	for (int i = 0; i < size; i++) {
		switch((m[i] = toupper(m[i]))) {
			case 'A': putchar('4');
				break;
			case 'B': putchar('8');
				break;
			case 'E': putchar('3');
				break;
			case 'I': putchar('1');
				break;
			case 'O': putchar('0');
				break;
			case 'S': putchar('5');
				break;
			default: putchar(m[i]);
				break;
		}
	}
	printf("!!!!!!!!!\n");

	return 0;
}
