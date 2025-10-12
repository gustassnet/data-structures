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


    // Stress test: push and pop many elements
    initStack(&s);
    int N = 1000;
    for (int i = 0; i < N; ++i) {
        push(&s, i);
    }
    assert(size(&s) == N);
    for (int i = N - 1; i >= 0; --i) {
        assert(pop(&s) == i);
    }
    assert(isEmpty(&s));

    return 0;
}