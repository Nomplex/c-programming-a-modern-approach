#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	int result, n1, n2;
	char ch;

	printf("Enter an RPN expression: ");
	do {
		scanf(" %c", &ch);
		switch (ch) {
			case '+':
				n2 = pop();
				n1 = pop();
				result = n1 + n2;
				push(result);
				break;
			case '-':
				n2 = pop();
				n1 = pop();
				result = n1 - n2;
				push(result);
				break;
			case '*':
				n2 = pop();
				n1 = pop();
				result = n1 * n2;
				push(result);
				break;
			case '/':
				n2 = pop();
				n1 = pop();
				result = n1 / n2;
				push(result);
				break;
			case '=':
				printf("Value of expression: %d\n", pop());
				printf("Enter an RPN expression: ");
				make_empty();
				break;
			case 'q':
				exit(EXIT_SUCCESS);
				break;
			default:
				if (ch >= 48 && ch <= 57)
					push(convert(ch));
				break;
		}
	} while (true);
}
