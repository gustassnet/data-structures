#include "Stack.h"
#include <stdio.h>   
#include <stdlib.h> 

#define ERROR_MEMORY "Error! Failed to allocate memory!\n"
#define ERROR_NO_ELEMENT "Error! Stack is empty!\n"

void initStack(Stack *s) {
    s->items = NULL;
    s->capacity = 0;
    s->top = -1;
}

void reallocStack(Stack *s, size_t newCapacity) {
    if (newCapacity == 0) {
        newCapacity++;
    }

    Item_type *newItems = realloc(s->items, sizeof(Item_type) * newCapacity);
    if (newItems == NULL) {
        printf(ERROR_MEMORY);
        exit(EXIT_FAILURE);
    }

    s->items = newItems;
    s->capacity = newCapacity;
}

void push(Stack *s, Item_type item) {
    if (s->capacity == s->top + 1) {
        reallocStack(s, s->capacity * 2); 
    }
    s->items[++s->top] = item;
}

Item_type pop(Stack *s) {
    if (s->top == -1) {
        printf(ERROR_NO_ELEMENT);
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

Item_type peek(Stack *s) {
    if (s->top == -1) {
        printf(ERROR_NO_ELEMENT);
        exit(EXIT_FAILURE);
    }
    return s->items[s->top];
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

size_t size(Stack *s) {
    return s->top + 1;
}

void freeStack(Stack *s) {
    free(s->items);
    s->items = NULL;
    s->capacity = 0;
    s->top = -1;
}