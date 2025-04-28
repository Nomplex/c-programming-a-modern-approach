#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

int convert(char c);
bool is_empty(void);
bool is_full(void);
void push(int c);
int pop(void);
int evaluate_RPN_expression(const char *expression);

int main(void)
{
	char expression[STACK_SIZE+1], ch, *p;

	while (true) {
		p = expression;
		printf("Enter an RPN expression: ");
		while (p < expression + STACK_SIZE && (ch = getchar()) != '\n')
			*p++ = ch;
		*p = '\0';

		printf("Result of expression: %d\n", evaluate_RPN_expression(expression));
	}
}

int evaluate_RPN_expression(const char *expression)
{
	int n1, n2, result = 0;
	while (*expression) {
		switch(*expression) {
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
				result = pop();
				top = 0;
				break;
			case 'q':
				exit(EXIT_SUCCESS);
				break;
			default:
				if (*expression >= 48 && *expression <= 57)
					push(convert(*expression));
		}

		expression++;
	}

	return result;
}

int convert(char c) {
	return c - '0';
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int c)
{
	if (is_full()) {
		printf("Expression is too complex\n");
		exit(EXIT_FAILURE);
	}
	else
		contents[top++] = c;
}

int pop(void)
{
	if (is_empty()) {
		printf("Not enough operands in expression\n");
		exit(EXIT_FAILURE);
	}
	else
		return contents[--top];
}

