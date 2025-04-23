#include <stdio.h>

int main(void)
{
	char phone[15], ch;
	int size = 0;

	printf("Enter phone number: ");
	/* I think I could condense this loop: while((phone[size++] = getchar()) != '\n') */
	while (size < 15 && (ch = getchar()) != '\n') {
		phone[size++] = ch;
	}

	printf("In numeric form: ");
	for (int i = 0; i < size; i++) {
		switch (phone[i]) {
			case 'A': case 'B': case 'C':
				printf("2");
				break;
			case 'D': case 'E': case 'F':
				printf("3");
				break;
			case 'G': case 'H': case 'I':
				printf("4");
				break;
			case 'J': case 'K': case 'L':
				printf("5");
				break;
			case 'M': case 'N': case 'O':
				printf("6");
				break;
			case 'P': case 'R': case 'S':
				printf("7");
				break;
			case 'T': case 'U': case 'V':
				printf("8");
				break;
			case 'W': case 'X': case 'Y':
				printf("9");
				break;
			default:
				printf("%c", phone[i]);
		}
	}
	putchar('\n');

	return 0;
}
