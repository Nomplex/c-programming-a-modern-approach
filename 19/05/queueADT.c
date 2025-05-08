#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 10

struct queue_type {
	Item contents[QUEUE_SIZE];
	int nextEnqueue;
	int nextDequeue;
	int len;
};

// An insertion or removal that would cause either of the first two integers to be
// incremented past the end of the array should instead reset the variable to zero
// causing it to wrap around.

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

static void safeInc(int *i)
{
	if (*i + 1 >= QUEUE_SIZE)
		*i = 0;
	else
		*i = *i + 1;
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: queue could not be created.");
	q->nextEnqueue = 0;
	q->nextDequeue = 0;
	q->len = 0;
	return q;
}

void enqueue(Queue q, Item i)
{
	if (is_full(q))
		terminate("Error in enqueue: queue is full.");
	q->contents[q->nextEnqueue] = i;
	safeInc(&q->nextEnqueue);
	q->len++;
}

Item dequeue(Queue q)
{
	Item i;
	if (is_empty(q))
		terminate("Error in dequeue: queue is empty.");
	i = q->contents[q->nextDequeue];
	safeInc(&q->nextDequeue);
	q->len--;
	return i;
}

Item peek_first(Queue q)
{
	return q->contents[q->nextDequeue];
}

Item peek_last(Queue q)
{
	return q->contents[q->len-1];
}

bool is_empty(Queue q)
{
	return q->len == 0;
}

bool is_full(Queue q)
{
	return q->len == QUEUE_SIZE;
}

void destroy(Queue q)
{
	free(q);
}
