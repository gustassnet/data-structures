#include "Stack.h"
#include <stdio.h>   
#include <stdlib.h> 

#define ERROR_EMPTY "Error! Stack is empty!\n"
#define ERROR_FULL "Error! Stack is full!\n"

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, Item_type item) {
    if (isFull(s)) {
        fprintf(stderr, ERROR_FULL);
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = item;
}

Item_type pop(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, ERROR_EMPTY);
        exit(EXIT_FAILURE);
    }

    Item_type value = s->items[s->top--];

    return value;
}

Item_type peek(Stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, ERROR_EMPTY);
        exit(EXIT_FAILURE);
    }
    return s->items[s->top];
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return  s->top + 1 == MAX_CAPACITY;
}

size_t size(Stack *s) {
    return s->top + 1;
}