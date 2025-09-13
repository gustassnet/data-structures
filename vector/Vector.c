#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

void reallocVector(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        newCapacity++;
    }

    Item_type *new_items = realloc(v->items, sizeof(Item_type) * newCapacity);
    if (new_items == NULL) {
        printf(ERROR_MEMORY);
        exit(EXIT_FAILURE);
    }
    v->items = new_items;
    v->capacity = newCapacity;
}

void initVector(vector *v) {
    v->items = NULL;
    v->capacity = 0;
    v->size = 0;
}

void freeVector(vector *v) {
    free(v->items);
    v->items = NULL;
    v->capacity = 0;
    v->size = 0;
}

size_t getSize(vector *v) {
    return v->size;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity && v->size != 0;
}

char* toString(vector *v) {
    if (v->size == 0) {
        char *empty = malloc(1);
        if (!empty) return NULL;
        empty[0] = '\0';
        return empty;
    }

    int *items = (int*)v->items;

    size_t total_len = 0;
    for (size_t i = 0; i < v->size; ++i) {
        total_len += snprintf(NULL, 0, "%d ", items[i]);
    }

    char *buffer = malloc(total_len + 1);
    if (!buffer) return NULL;

    size_t offset = 0;
    for (size_t i = 0; i < v->size; ++i) {
        offset += sprintf(buffer + offset, "%d", items[i]);
        if (i < v->size - 1) {
            buffer[offset++] = ' ';
        }
    }

    return buffer;
}

void cloneVector(vector *v, vector *dest) {
    dest->items = NULL;
    dest->capacity = v->capacity;
    dest->size = v->size;
    dest->items = malloc(dest->capacity * sizeof(Item_type));
    if (dest->items == NULL) {
        printf(ERROR_MEMORY);
        exit(EXIT_FAILURE);
        return;
    }

    for (size_t i = 0; i < v->size; ++i) {
        dest->items[i] = v->items[i];
    }
}

void makeEmpty(vector *v) {
    v->size = 0;
}

void addElement(vector *v, Item_type item) {
    if (v->capacity == v->size) {
        reallocVector(v, v->capacity * 2);
    }
    v->items[v->size++] = item;
}

void setElementAt(vector *v, ssize_t index, Item_type item) {
    if (index < 0 || (size_t)index >= v->size) {
        printf(ERROR_NO_ELEMENT);
        exit(EXIT_FAILURE);
    }
    v->items[index] = item;
}

Item_type getElementAt(vector *v, ssize_t index) {
    if (index < 0 || (size_t)index >= v->size) {
        printf(ERROR_NO_ELEMENT);
        exit(EXIT_FAILURE);
    }
    return v->items[index];
}

void removeElementAt(vector *v, ssize_t index) {
    if (index < 0 || (size_t)index >= v->size) {
        printf(ERROR_NO_ELEMENT);
        exit(EXIT_FAILURE);
    }

    for (size_t i = (size_t)index; i < v->size - 1; ++i) {
        v->items[i] = v->items[i + 1];
    }

    v->size--;

    if (v->size == 0) {
        freeVector(v);
    } else if (v->capacity / 2 == v->size) {
        reallocVector(v, v->capacity / 2);
    }
}

void insertElementAt(vector *v, ssize_t index, Item_type item) {
    if (index < 0 || (size_t)index > v->size) {
        printf(ERROR_CANNOT_INSERT);
        exit(EXIT_FAILURE);
    }

    if (v->capacity == v->size) {
        reallocVector(v, v->capacity * 2);
    }

    for (size_t i = v->size; i > (size_t)index; --i) {
        v->items[i] = v->items[i - 1];
    }

    v->items[index] = item;
    v->size++;
}