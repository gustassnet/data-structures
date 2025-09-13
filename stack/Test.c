#include <assert.h>
#include <string.h>
#include "Stack.h"

int main() {
    Stack s;

    // Stack initialization
    initStack(&s);
    assert(size(&s) == 0);
    assert(isEmpty(&s) == true);


    // Adding the first element
    push(&s, 2);
    assert(size(&s) == 1);
    assert(peek(&s) == 2);
    assert(isEmpty(&s) == false);


    // Adding the second element
    push(&s, 9);
    assert(size(&s) == 2);
    assert(peek(&s) == 9);
    assert(isEmpty(&s) == false);


    // Removing the second element
    assert(pop(&s) == 9);
    assert(size(&s) == 1);
    assert(peek(&s) == 2);
    assert(isEmpty(&s) == false);


    // Removing the first element
    assert(pop(&s) == 2);
    assert(size(&s) == 0);
    assert(isEmpty(&s) == true);


    // Freeing memory
    freeStack(&s);
}