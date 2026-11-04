# Queue implementation in C language

## 1. Introduction

This document describes the implementation of a queue in C using a circular singly linked list. It presents the core functions, their descriptions and usage. It explains how to modify the code to support various data types.

## 2. Features

- Circular singly linked list implementation.
- Dynamic memory allocation for each element.
- Insertion and removal of elements.
- Access to the front and back elements.
- Element search.
- Memory cleanup.
- Configurable element type through the `Item_type`.

## 3. Implementation Details

The queue is implemented using a circular singly linked list, where each node stores an element and a pointer to the next node.

The Queue has three fields:

- `head` – pointer to the first node in the queue.
- `tail` – pointer to the last node in the queue.
- `size` – number of elements currently stored in the queue.

The last node points back to the first node, forming a circular structure.

### Enqueue

Adds a new element to the end of the queue. The new node becomes the tail.

### Dequeue

Removes and returns the first element in the queue. The head pointer is updated to the next node and the memory of removed node is freed.

### Memory Management

Each node is dynamically allocated using malloc() when an element is added. Its memory is released using free() when an element is removed or the queue is cleared.

## 4. Function Documentation

### 1. `void initQueue(Queue *q)`

**Description:** Initializes an empty queue.

**Usage:**

```c
Queue q;
initQueue(&q);
```

### 2. `size_t size(Queue *q)`

**Description:** Returns the number of elements in the queue.

**Usage:**

```c
printf("Queue size: %zu\n", size(&q));
```

### 3. `bool isEmpty(Queue *q)`

**Description:** Checks whether the queue is empty. Returns `true` if the queue is empty; otherwise, returns `false`.

**Usage:**

```c
if (isEmpty(&q)) {
    printf("Queue is empty\n");
}
```

### 4. `void enqueue(Queue *q, Item_type item)`

**Description:** Adds the specified element to the end of the queue.

**Usage:**

```c
enqueue(&q, 1);
```

### 5. `Item_type dequeue(Queue *q)`

**Description:** Removes and returns the oldest element (the front element) of the queue. If the queue is empty, prints an error message and returns `-1`.

**Usage:**

```c
printf("%d", dequeue(&q));
```

### 6. `Item_type front(Queue *q)`

**Description:** Returns the oldest element (the front element) without removing it. If the queue is empty, prints an error message and returns `-1`.

**Usage:**

```c
printf("%d", front(&q));
```

### 7. `Item_type back(Queue *q)`

**Description:** Returns the newest element (the back element) without removing it. If the queue is empty, prints an error message and returns `-1`.

**Usage:**

```c
printf("%d", back(&q));
```

### 8. `bool contains(Queue *q, Item_type item)`

**Description:** Checks whether the queue contains the specified element. Returns `true` if the element is found; otherwise, returns `false`.

**Usage:**

```c
Item_type item = 10;

if (contains(&q, item)) {
    printf("Queue contains element: %d", item);
}
```

### 9. `void clearQueue(Queue *q)`

**Description:** Removes all elements from the queue and frees the allocated memory.

**Usage:**

```c
clearQueue(&q);
```

### 10. `void printQueue(Queue *q)`

**Description:** Prints all elements in the queue. If the queue is empty, prints an error message.

**Usage:**

```c
printQueue(&q);
```

### 11. `char* toString(Queue *q)`

**Description:** Returns a dynamically allocated string containing all queue elements separated by spaces. If the queue is empty, returns an empty string. The caller is responsible for freeing the returned memory.

**Usage:**

```c
char *str = toString(&q);
printf("%s\n", str);
free(str);
```

## 5. Data type configuration

Currently, the queue stores integers (`int`). To allow it to accept other data types, it needs to be modified:

1. **Change `typedef int Item_type;**

```c
typedef int Item_type;   // Convert int to the desired type (example: double)
```

2. **Update `sprintf` formatting specifiers:**

- `%d` → `%lf` (`double` type)

## 6. Building and Running

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

- Compiles the files using Makefile.
- Executes the generated test.exe.
- Redirects standard output to test.txt.

## 7. Tests

The project includes automated tests using the C standard library's assert.h.

The tests cover:

- Queue initialization.
- Adding elements to the queue using `enqueue()`.
- Removing elements using `dequeue()`.
- Retrieving the front and back elements.
- Checking queue size and whether it is empty.
- Searching for elements using `contains()`.
- Converting queue elements to a string using `toString()`.
- Printing queue elements using `printQueue()`.
- Clearing the queue and verifying that allocated memory is released.

If all assertions pass, the test program completes successfully without giving any assertion failures.