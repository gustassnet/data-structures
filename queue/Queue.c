#include <stdio.h>
#include "Queue.h"

#define ERROR_MEMORY "Error! Failed to allocate memory!\n"
#define ERROR_EMPTY "Error! Queue is empty!\n"

void initQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

size_t size(Queue *q) {
    return q->size;
}

bool isEmpty(Queue *q) {
    return (q->head == NULL && q->tail == NULL);
}

void enqueue(Queue *q, Item_type item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf(ERROR_MEMORY);
        exit(EXIT_FAILURE);
    }

    newNode->item = item;
    newNode->next = NULL;

    if (q->head == NULL) {
        newNode->next = newNode;
        q->head = newNode;
        q->tail = newNode;
    } else {
        newNode->next = q->head;
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->size++;
}

Item_type dequeue(Queue *q) {
    if (q->head == NULL) {
        printf(ERROR_EMPTY);
        return -1;
    }
   
    Node *temp = q->head;
    Item_type item = temp->item;
   
    if (q->head == q->tail) {
        // Single item queue
        q->head = NULL;
        q->tail = NULL;
    } else {
        // Multiple item queue
        q->head = temp->next;
        q->tail->next = q->head; 
    }

    q->size--;
    free(temp);
    return item;
}

Item_type front(Queue *q) {
    if (q->head == NULL) {
        printf(ERROR_EMPTY);
        return -1;
    }

    return q->head->item;
}

Item_type back(Queue *q) {
    if (q->tail == NULL) {
        printf(ERROR_EMPTY);
        return -1;
    }

    return q->tail->item;
}

bool contains(Queue *q, Item_type item) {
    if (q->head == NULL) {
        return false;
    }

    Node *current = q->head;
   
    do {
        if (current->item == item) {
            return true;
        }
        current = current->next;
    } while (current != q->head);
   
    return false;
}

void clearQueue(Queue *q) {
    if (q->head == NULL) return;
    Node *current = q->head;
   
    do {
        Node *temp = current;
        current = current->next;
        free(temp);
    } while (current != q->head);
   
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

void printQueue(Queue *q) {
    if (q->head == NULL) {
        printf(ERROR_EMPTY);
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

char* toString(Queue *q) {
    if (q == NULL || q->head == NULL) {
        char *empty = malloc(1);
        if (!empty) return NULL;
        empty[0] = '\0';
        return empty;
    }

    size_t total_len = 0;
    Node *current = q->head;

    do {
        total_len += snprintf(NULL, 0, "%d ", current->item);
        current = current->next;
    } while (current != q->head);

    char *buffer = malloc(total_len + 1);
    if (!buffer) return NULL;

    current = q->head;
    size_t offset = 0;

    do {
        offset += sprintf(buffer + offset, "%d ", current->item);
        current = current->next;
    } while (current != q->head);

    if (offset > 0) {
        buffer[offset - 1] = '\0';
    }

    return buffer;
}
