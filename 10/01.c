#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
	char ch;
	printf("Enter parentheses and/or braces: ");
	while ((ch = getchar()) != '\n') {
		switch (ch) {
			case '{': case '[': case '(':
				push(ch);
				break;
			case '}':
				if (pop() != '{') {
					printf("Parentheses/braces aren't nested properly\n");
					return 0;
				}
				break;
			case ']': 
				if (pop() != '[') {
					printf("Parentheses/braces aren't nested properly\n");
					return 0;
				}
				break;
			case ')':
				if (pop() != '(') {
					printf("Parentheses/braces aren't nested properly\n");
					return 0;
				}
				break;
		}
	}

	if (is_empty())
		printf("Parentheses/braces are nested properly\n");
	else
		printf("Parentheses/braces aren't nested properly\n");

	return 0;

}

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(char c)
{
	if (is_full())
		stack_overflow();

	contents[top++] = c;
}

char pop(void)
{
	if (is_empty())
		stack_underflow();

	return contents[--top];
}

void stack_overflow(void)
{
	printf("Stack Overflow\n");
	exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
	printf("Stack Underflow\n");
	exit(EXIT_FAILURE);
}
