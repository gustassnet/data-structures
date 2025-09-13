#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef int Item_type;

typedef struct Stack {
    Item_type *items;
    size_t capacity;
    size_t top;
} Stack;

void initStack(Stack *s);
void reallocStack(Stack *s, size_t newSize);
void push(Stack *s, Item_type item);
Item_type pop(Stack *s);
Item_type peek(Stack *s);
bool isEmpty(Stack *s);
size_t size(Stack *s);
void freeStack(Stack *s);

#endif