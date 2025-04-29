#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

int convert(char c) {
	return c - '0';
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
