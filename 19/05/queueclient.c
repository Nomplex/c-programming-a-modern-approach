#include <stdio.h>
#include "queueADT.h"

void printOut(int n);

int main(void)
{
	Queue q1 = create(), q2 = create();

	for (int i = 1; i <= 10; i++) {
		enqueue(q1, i);
	}

	for (int i = 1; i <= 3; i++) {
		enqueue(q2, i);
	}

	for (int i = 1; i <= 3; i++) {
		printOut(dequeue(q2));
	}

	printOut(dequeue(q1));
	enqueue(q1, 0);

	return 0;
}

void printOut(int n)
{
	printf("Dequeued Number is: %d\n", n);
}
