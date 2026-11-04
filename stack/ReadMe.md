# Stack Implementation in C

## 1. Introduction

This document describes the implementation of a stack data sturcture in C using a fixed-size array. It presents the core functions, their descriptions and usage. It explains how to modify the code to support various data types.

## 2. Features

- Fixed capacity of 1000 elements.
- Push and pop operations.
- Access to the top element without removing it.
- Stack size and state checking.

## 3. Implementation Details

The stack is implemented using a fixed-size array. The last element added to the stack is the first one to be removed.

The Stack has two fields:

- **items** – array used to store stack elements.
- **top** – index of the top element in the stack. It is initialized to `-1`, meaning that the stack is empty.

### Push

Adds a new element to the top of the stack. The `top` index is incremented. If the stack is full, an error message is displayed and the program terminates.

### Pop

Removes and returns the top element of the stack. The `top` index is decremented after retrieving the element. If the stack is empty, an error message is displayed and the program terminates.

### Peek

Returns the top element without removing it from the stack. If the stack is empty, an error message is displayed and the program terminates.

## 4. Function Documentation

### 1. `void initStack(Stack *s)`

**Description:** Initializes an empty stack by setting the top index to `-1`.

**Usage:**

```c
Stack s;
initStack(&s);
```

### 2. `void push(Stack *s, Item_type item)`

**Description:** Adds the specified element to the top of the stack. If the stack is full, prints an error message and terminates the program.

**Usage:**

```c
push(&s, 10);
```

### 3. `Item_type pop(Stack *s)`

**Description:** Removes and returns the top element of the stack. If the stack is empty, prints an error message and terminates the program.

**Usage:**

```c
printf("%d", pop(&s));
```

### 4. `Item_type peek(Stack *s)`

**Description:** Returns the top element without removing it. If the stack is empty, prints an error message and terminates the program.

**Usage:**

```c
printf("%d", peek(&s));
```

### 5. `bool isEmpty(Stack *s)`

**Description:** Checks whether the stack is empty. Returns `true` if the stack is empty; otherwise, returns `false`.

**Usage:**

```c
if (isEmpty(&s)) {
    printf("Stack is empty\n");
}
```

### 6. `bool isFull(Stack *s)`

**Description:** Checks whether the stack has reached its maximum capacity. Returns `true` if the stack is full; otherwise, returns `false`.

**Usage:**

```c
if (isFull(&s)) {
    printf("Stack is full\n");
}
```

### 7. `size_t size(Stack *s)`

**Description:** Returns the number of elements currently stored in the stack.

**Usage:**

```c
printf("Stack size: %zu\n", size(&s));
```


## 5. Data type configuration

Currently, the stack stores integers (`int`). To allow it to accept other data types, it needs to be modified:

```c
typedef int Item_type;   // Convert int to the desired type (example: double)
```


## 7. Building and Running

### Option 1: Using Make

Build the project:

```bash
make
```

Clean compiled files:

```bash
make clean
```

### Option 2: Using the Windows Script

The project includes a go.cmd script that automates compilation and test execution.

Run:

```cmd
go.cmd
```

The script:

- Compiles the files using the Makefile.
- Executes the generated `test.exe`.
- Redirects standard output to `test.txt`.

## 8. Tests

The project includes automated tests using the C standard library's `assert.h`.

The tests cover:

- Stack initialization.
- Adding elements using `push()`.
- Retrieving the top element using `peek()`.
- Removing elements using `pop()`.
- Checking stack size and whether it is empty.
- Stress testing by inserting and removing 1000 elements (maximum capacity).

If all assertions pass, the test program completes successfully without giving any assertion failures.