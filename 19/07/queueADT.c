#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
	Item data;
	struct node *next;
};

struct queue_type {
	struct node *first;
	struct node *last;
	int len;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: queue could not be created.");
	q->first = NULL;
	q->last = NULL;
	q->len = 0;
	return q;
}

void enqueue(Queue q, Item i)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in enqueue: node creation failed");

	new_node->data = i;
	new_node->next = NULL;

	if (q->len == 0)
		q->first = q->last = new_node;
	else {
		q->last->next = new_node;
		q->last = new_node;
	}
	q->len++;
}

Item dequeue(Queue q)
{
	struct node *old_node;
	Item i;

	if (is_empty(q))
		terminate("Error in dequeue: queue is empty.");

	old_node = q->first;
	q->first = old_node->next;

	i = old_node->data;
	free(old_node);
	q->len--;
	return i;
}

Item peek_first(Queue q)
{
	if (is_empty(q))
		terminate("Error in peek_first: queue is empty");

	return q->first->data;
}

Item peek_last(Queue q)
{
	if (is_empty(q))
		terminate("Error in peek_last: queue is empty");

	return q->last->data;
}

bool is_empty(Queue q)
{
	return q->len == 0;
}

bool is_full(Queue q)
{
	return false;
}

void destroy(Queue q)
{
	while (!is_empty(q))
		dequeue(q);
	free(q);
}
