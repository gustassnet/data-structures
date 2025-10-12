#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef int Item_type;
#define MAX_CAPACITY 1000

typedef struct Stack {
    Item_type items[MAX_CAPACITY];
    int top;
} Stack;

void initStack(Stack *s);
void push(Stack *s, Item_type item);
Item_type pop(Stack *s);
Item_type peek(Stack *s);
bool isEmpty(Stack *s);
bool isFull(Stack *s);
size_t size(Stack *s);

#endif