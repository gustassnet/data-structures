# Stack Implementation in C

This program demonstrates a stack data structure implemented in C.

## Features

- **Push**: Add an element to the top of the stack.
- **Pop**: Remove the top element from the stack.
- **Peek**: View the top element without removing it.
- **isEmpty**: Check if the stack is empty.
- **isFull**: Check if the stack is full.

## How to Use

1. Clone or download the repository.
2. Build the project using `make`:
    ```
    make
    ```
3. Run the test executable:
    ```
    ./test
    ```

## Example Functions

```c
// Initiate 
Stack stack;
initStack(&stack);

// Push an element onto the stack
push(&stack, 10);

// Pop the top element
int value = pop(&stack);

// Peek at the top element
int top = peek(&stack);

// Check if the stack is empty
if (isEmpty(&stack)) {
    printf("Stack is empty.\n");
}
```