#include <stdio.h>
#include "stackADT3.h"

void printLen(char *name, int len);

int main(void)
{
	Stack s1, s2;
	char *n;

	s1 = create();
	s2 = create();

	push(s1, "a");
	printLen("s1", length(s1));
	push(s1, "b");
	printLen("s1", length(s1));

	n = (char *) pop(s1);
	printf("Popped %s from s1\n", n);
	printLen("s1", length(s1));
	push(s2, n);
	printLen("s2", length(s2));
	
	n = (char *) pop(s1);
	printf("Popped %s from s1\n", n);
	printLen("s1", length(s1));
	push(s2, n);
	printLen("s2", length(s2));

	destroy(s1);

	while (!is_empty(s2)) {
		printf("Popped %s from s2\n", (char *) pop(s2));
		printLen("s2", length(s2));
	}

	push(s2, "c");
	printLen("s2", length(s2));

	make_empty(s2);
	printLen("s2", length(s2));

	if (is_empty(s2))
		printf("s2 is empty\n");
	else
		printf("s2 is not empty\n");

	destroy(s2);

	return 0;
}

void printLen(char *name, int len)
{
	printf("Length of %s is now %d\n", name, len);
}
