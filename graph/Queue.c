#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue init_queue() {
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    return q;
}

void enqueue(Queue *q, Item_type item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->item = item;
   
    if (q->head == NULL) {
        newNode->next = newNode;
        q->head = newNode;
        q->tail = newNode;
    } else {
        newNode->next = q->head;
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

Item_type dequeue(Queue *q) {
    // Empty queue
    if (q->head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
   
    Node *temp = q->head;
    Item_type item = temp->item;
   
    // Single item queue
    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
        free(temp);
        return item;
    }
   
    // Multiple item queue
    q->head = temp->next;
    q->tail->next = q->head;
    free(temp);
    return item;
}

unsigned is_empty(Queue *q) {
    return (q->head == NULL && q->tail == NULL);
}

Item_type peek(Queue *q) {
    if (q->head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
   
    return q->head->item;
}

void free_queue(Queue *q) {
    if (q->head == NULL) return;
    Node *current = q->head;
   
    do {
        Node *temp = current;
        current = current->next;
        free(temp);
    } while (current != q->head);
   
    q->head = NULL;
    q->tail = NULL;
}

void print_queue(Queue *q) {
    if (q->head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    Node *current = q->head;
    do {
        printf("%d ", current->item);
        current = current->next;
    } while (current != q->head);
    printf("\n");
}