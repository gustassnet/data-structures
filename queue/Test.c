#include <assert.h>
#include <string.h>
#include "Queue.h"

int main() {
    Queue q;

    // Queue initialization
    initQueue(&q);
    assert(size(&q) == 0);
    assert(isEmpty(&q) == true);
    assert(front(&q) == -1);
    assert(back(&q) == -1);
    assert(contains(&q, 2) == false);
    printQueue(&q);
    assert(strcmp(toString(&q), "") == 0);


    // Adding the first element
    enqueue(&q, 1);
    assert(size(&q) == 1);
    assert(isEmpty(&q) == false);
    assert(front(&q) == 1);
    assert(back(&q) == 1);
    assert(contains(&q, 1) == true);
    printQueue(&q);
    assert(strcmp(toString(&q), "1") == 0);


    // Adding the second element
    enqueue(&q, 2);
    assert(size(&q) == 2);
    assert(isEmpty(&q) == false);
    assert(front(&q) == 1);
    assert(back(&q) == 2);
    assert(contains(&q, 2) == true);
    printQueue(&q);
    assert(strcmp(toString(&q), "1 2") == 0);


    // Adding the third element
    enqueue(&q, 3);
    assert(size(&q) == 3);
    assert(isEmpty(&q) == false);
    assert(front(&q) == 1);
    assert(back(&q) == 3);
    assert(contains(&q, 3) == true);
    printQueue(&q);
    assert(strcmp(toString(&q), "1 2 3") == 0);


    // Removing the first element
    assert(dequeue(&q) == 1);
    assert(size(&q) == 2);
    assert(isEmpty(&q) == false);
    assert(front(&q) == 2);
    assert(back(&q) == 3);
    printQueue(&q);
    assert(strcmp(toString(&q), "2 3") == 0);
    

    // Removing the second element
    assert(dequeue(&q) == 2);
    assert(size(&q) == 1);
    assert(isEmpty(&q) == false);
    assert(front(&q) == 3);
    assert(back(&q) == 3);
    printQueue(&q);
    assert(strcmp(toString(&q), "3") == 0);


    // Removing the third element
    assert(dequeue(&q) == 3);
    assert(size(&q) == 0);
    assert(isEmpty(&q) == true);
    assert(front(&q) == -1);
    assert(back(&q) == -1);
    printQueue(&q);
    assert(strcmp(toString(&q), "") == 0);


    // Freeing memory
    enqueue(&q, 1);
    assert(size(&q) == 1);
    assert(isEmpty(&q) == false);
    assert(strcmp(toString(&q), "1") == 0);    
    clearQueue(&q);
    assert(isEmpty(&q) == true);
    assert(strcmp(toString(&q), "") == 0);

    return 0;
}