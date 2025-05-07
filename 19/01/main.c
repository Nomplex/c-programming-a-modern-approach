#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void error(Stack s);

int main(void)
{
	Stack s = create();
	char ch;
	printf("Enter parentheses and/or braces: ");
	while ((ch = getchar()) != '\n') {
		switch (ch) {
			case '{': case '[': case '(':
				push(s, ch);
				break;
			case '}':
				if (pop(s) != '{')
					error(s);
				break;
			case ']':
				if (pop(s) != '[')
					error(s);
				break;
			case ')':
				if (pop(s) != '(')
					error(s);
				break;
		}
	}

	if (!is_empty(s))
		error(s);

	printf("Parentheses/braces are nested properly\n");
	return 0;
}

void error(Stack s)
{
	printf("Parentheses/braces aren't nested properly\n");
	destroy(s);
	exit(EXIT_SUCCESS);
}
