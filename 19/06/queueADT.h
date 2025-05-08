#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue create(int l);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek_first(Queue q);
Item peek_last(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void destroy(Queue q);

#endif
