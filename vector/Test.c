#include <assert.h>
#include <string.h>
#include "vector.h"

int main() {
    vector v;

    // Vector inicialization
    initVector(&v);
    assert(getSize(&v) == 0);
    assert(isEmpty(&v) == true);
    assert(isFull(&v) == false);
    assert(strcmp(toString(&v), "") == 0);

    // Add the first element
    addElement(&v, 2);
    assert(getElementAt(&v, 0) == 2);
    assert(getSize(&v) == 1);
    assert(isEmpty(&v) == false);
    assert(isFull(&v) == true);
    assert(strcmp(toString(&v), "2") == 0);


    // Changing the first element
    setElementAt(&v, 0, 3);
    assert(getElementAt(&v, 0) == 3);
    assert(strcmp(toString(&v), "3") == 0);


    // Add the second element
    addElement(&v, 3);
    assert(getElementAt(&v, 1) == 3);
    assert(getSize(&v) == 2);
    assert(isEmpty(&v) == false);
    assert(isFull(&v) == true);
    assert(strcmp(toString(&v), "3 3") == 0);


    // Changing the second element
    setElementAt(&v, 1, 4);
    assert(getElementAt(&v, 1) == 4);
    assert(strcmp(toString(&v), "3 4") == 0);


    // Add the third element
    addElement(&v, 4);
    assert(getElementAt(&v, 2) == 4);
    assert(getSize(&v) == 3);
    assert(isEmpty(&v) == false);
    assert(isFull(&v) == false);
    assert(strcmp(toString(&v), "3 4 4") == 0);


    // CHanging the third element
    setElementAt(&v, 2, 5);
    assert(getElementAt(&v, 2) == 5);
    assert(strcmp(toString(&v), "3 4 5") == 0);


    // Copying the vector
    vector v2;
    initVector(&v2);
    cloneVector(&v, &v2);
    assert(getSize(&v2) == 3);
    assert(strcmp(toString(&v2), "3 4 5") == 0);

    // Removing the second element
    removeElementAt(&v, 1);
    assert(getSize(&v) == 2);
    assert(getElementAt(&v, 1) == 5);
    assert(isEmpty(&v) == false);
    assert(strcmp(toString(&v), "3 5") == 0);


    // Returning the element
    insertElementAt(&v, 1, 4);
    assert(getSize(&v) == 3);
    assert(getElementAt(&v, 1) == 4);
    assert(isEmpty(&v) == false);
    assert(strcmp(toString(&v), "3 4 5") == 0);
    

    // Removing the third element
    removeElementAt(&v, 2);
    assert(getSize(&v) == 2);
    assert(strcmp(toString(&v), "3 4") == 0);


    // Removing the second element
    removeElementAt(&v, 1);
    assert(getSize(&v) == 1);
    assert(strcmp(toString(&v), "3") == 0);


    // Removing the first element
    removeElementAt(&v, 0);
    assert(getSize(&v) == 0);
    assert(strcmp(toString(&v), "") == 0);


    // Freeing memory
    freeVector(&v2);
    freeVector(&v);
    return 0;
}