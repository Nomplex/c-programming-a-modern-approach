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
				top = 0;
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

