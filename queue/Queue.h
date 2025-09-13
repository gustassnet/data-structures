#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Item_type;

typedef struct Node {
    Item_type item;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *head;
    struct Node *tail;
    size_t size;
} Queue;

void initQueue(Queue *q);
size_t size(Queue *q);
bool isEmpty(Queue *q);
void enqueue(Queue *q, Item_type item);
Item_type dequeue(Queue *q);
Item_type front(Queue *q);
Item_type back(Queue *q);
bool contains(Queue *q, Item_type item);
void clearQueue(Queue *q);
void printQueue(Queue *q);
char* toString(Queue *q);

#endif