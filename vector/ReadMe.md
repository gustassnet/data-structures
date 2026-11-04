# Vector implementation in C language

## 1. Introduction

This document describes the implementation of a vector (dynamic array) in the C language. It presents the core functions, their descriptions and usage. It explains how to modify the code to support various data types.

## 2. Features

- Dynamic array initialization using dynamically allocated memory.
- Automatic capacity doubling when the vector becomes full.
- Automatic capacity reduction when the number of elements reaches half of the allocated capacity.
- Adding elements to the end of the vector.
- Inserting and removing elements at specified indices.
- Accessing and modifying elements.
- Creating copies of vectors.
- Checking vector `size`, `capacity` status and whether it is empty.
- Clearing the vector and freeing allocated memory.
- Configurable element type through the `Item_type` definition.

## 3. Implementation Details

The vector is implemented using a dynamically allocated array. It has three properties:

`items` – pointer to the first item of dynamically allocated memory.

`size` – current number of elements stored in the vector.

`capacity` – total number of elements that can currently be stored.

### Memory Allocation and Resizing

Memory is allocated dynamically using `malloc()` and `realloc()`.

**Growing:** When the vector reaches its capacity, the allocated capacity is doubled.

**Shrinking:** When elements are removed and the vector size reaches half of its capacity, the allocated memory is reduced by half.

**Memory cleanup:** When the vector becomes empty, its allocated memory is released.

## 4. Functions Documentation

### 1. `void initVector(vector *v)`

**Description:** Initializes an empty vector with an initial capacity of zero.

**Usage:**
```c
vector v;
initVector(&v);
```

### 2. `void freeVector(vector *v)`

**Description:** Frees all memory allocated for the vector and resets its properties.

**Usage:**
```c
freeVector(&v);
```

### 3. `size_t getSize(vector *v)`

**Description:** Returns the current number of elements stored in the vector.

**Usage:**
```c
printf("Vector size: %zu\n", getSize(&v));
```

### 4. `bool isEmpty(vector *v)`

**Description:** Checks whether the vector is empty. Returns `true` if the vector contains no elements; otherwise, returns `false`.

**Usage:**
```c
if (isEmpty(&v)) {
    printf("The vector is empty.\n");
}
```

### 5. `bool isFull(vector *v)`

**Description:** Checks whether the vector has reached its current capacity. Returns `true` if the vector is full; otherwise, returns `false`.

**Usage:**
```c
if (isFull(&v)) {
    printf("The vector is full.\n");
}
```

### 6. `char* toString(vector *v)`

**Description:** Converts the vector's elements into a string and returns a pointer to the resulting string. The caller is responsible for freeing the allocated memory.

**Usage:**
```c
char *str = toString(&v);
printf("%s\n", str);
free(str);
```

### 7. `void cloneVector(vector *v, vector *dest)`

**Description:** Creates an independent copy of the source vector and stores it in the destination vector.

**Usage:**
```c
vector v2;
initVector(&v2);

cloneVector(&v1, &v2);
```

### 8. `void makeEmpty(vector *v)`

**Description:** Removes all elements from the vector by resetting its size to zero. The allocated capacity is preserved.

**Usage:**
```c
makeEmpty(&v);
```

### 9. `void addElement(vector *v, Item_type item)`

**Description:** Appends a new element to the end of the vector. If the vector reaches its capacity, the capacity is automatically doubled.

**Usage:**
```c
addElement(&v, 10);
addElement(&v, 20);
```

### 10. `void setElementAt(vector *v, ssize_t index, Item_type item)`

**Description:** Updates the value of an element at the specified index. If the index is invalid, an error message is printed and the program terminates.

**Usage:**
```c
setElementAt(&v, 0, 30);
```

### 11. `Item_type getElementAt(vector *v, ssize_t index)`

**Description:** Returns the element stored at the specified index. If the index is invalid, an error message is printed and the program terminates.

**Usage:**
```c
printf("Element: %d\n", getElementAt(&v, 0));
```

### 12. `void removeElementAt(vector *v, ssize_t index)`

**Description:** Removes the element at the specified index and shifts the remaining elements to fill the gap. If the vector becomes empty, its allocated memory is freed. If its size reaches half of its capacity, the capacity is reduced by half.

**Usage:**
```c
removeElementAt(&v, 1);
```

### 13. `void insertElementAt(vector *v, ssize_t index, Item_type item)`

**Description:** Inserts an element at the specified index, shifting the subsequent elements to make room. If the vector reaches its capacity, the capacity is automatically doubled.

**Usage:**
```c
insertElementAt(&v, 1, 15);
```

## 5. Data type configuration

Currently, the vector stores integers (`int`). To allow it to accept other data types, it needs to be modified:

1. **Change `#define Item_type` type:**

```c
#define Item_type int   // Convert int to the desired type (example: double)
```

2. **Update `sprintf` formatting specifiers:**

- `%d` → `%lf` (`double` type)

## 6. Building and Running

### Option 1: Using Make

Build the project:

```c
make
```

Clean compiled files:

```c
make clean
```

### Option 2: Using the Windows Script

The project includes a go.cmd script that automates compilation and test execution.

Run:

```c
go.cmd
```

The script:

- Compiles the files using Makefile.
- Executes the generated test.exe.
- Redirects standard output to test.txt.

## 7. Tests

The project includes automated tests using the C standard library's assert.h.

The tests cover:

- Vector initialization.
- Adding elements and automatic capacity growth.
- Retrieving and modifying elements.
- Inserting and removing elements.
- Checking vector size and if empty/full.
- Creating and verifying copies.
- Clearing the vector and freeing allocated memory.

If all assertions pass, the test program completes successfully without giving any errors.