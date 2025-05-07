#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	Stack s = create();
	int n1, n2;
	char ch;


	printf("Enter an RPN expression: ");
	do {
		scanf(" %c", &ch);
		switch (ch) {
			case '+':
				n2 = pop(s);
				n1 = pop(s);
				push(s, n1 + n2);
				break;
			case '-':
				n2 = pop(s);
				n1 = pop(s);
				push(s, n1 - n2);
				break;
			case '*':
				n2 = pop(s);
				n1 = pop(s);
				push(s, n1 * n2);
				break;
			case '/':
				n2 = pop(s);
				n1 = pop(s);
				push(s, n1 / n2);
				break;
			case '=':
				printf("Value of expression: %d\n", pop(s));
				printf("Enter an RPN expression: ");
				break;
			case 'q':
				destroy(s);
				exit(EXIT_SUCCESS);
				break;
			default:
				if (ch >= 48 && ch <= 57)
					push(s, ch - '0');
				break;
		}
	} while (true);
}
