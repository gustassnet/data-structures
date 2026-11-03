#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

#define ERROR_MEMORY "Error! Could not allocate memory!\n"
#define ERROR_NO_ELEMENT "Error! Could not find element at this index!\n"
#define ERROR_CANNOT_INSERT "Error! Could not insert element!\n"

#define Item_type int      // Vector type

typedef struct Vector {
    Item_type *items;      // Item array
    size_t capacity;       // Vector capacity
    size_t size;          // Number of elements in the vector
} vector;

// Function to reallocate vector memory
// If the vector reaches its capacity, this function doubles the capacity
void reallocVector(vector *v, size_t capacity);

// Function to initialize a vector
void initVector(vector *v);

// Function to free the memory allocated for a vector
void freeVector(vector *v);

// Function to get the number of elements in a vector
size_t getSize(vector *v);

// Function to check if a vector is empty
bool isEmpty(vector *v);

// Function to check if a vector is full
bool isFull(vector *v);

// Function to convert a vector to a string
char* toString(vector *v);

// Function to create a copy of a vector
void cloneVector(vector *v, vector *dest);

// Function to clear a vector
void makeEmpty(vector *v);

// Function to add an element to a vector
void addElement(vector *v, Item_type item);

// Function to set the value of an element at a specific index
void setElementAt(vector *v, ssize_t index, Item_type item);

// Function to get an element by its index
Item_type getElementAt(vector *v, ssize_t index);

// Function to remove an element by its index
void removeElementAt(vector *v, ssize_t index);

// Function to insert an element at a specific index
void insertElementAt(vector *v, ssize_t index, Item_type item);

#endif