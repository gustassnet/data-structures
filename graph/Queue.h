#ifndef QUEUE_H
#define QUEUE_H

typedef int Item_type;

typedef struct Node {
    Item_type item;
    struct Node *next;
} Node;

typedef struct Queue {
    struct Node *head;
    struct Node *tail;
} Queue;

Queue init_queue();
void enqueue(Queue *q, Item_type item);
Item_type dequeue(Queue *q);
unsigned is_empty(Queue *q);
Item_type peek(Queue *q);
void free_queue(Queue *q);
void print_queue(Queue *q);

#endif