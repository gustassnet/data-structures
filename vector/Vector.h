#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

#define ERROR_MEMORY "Klaida! Nepavyko paskirstyti atminties!\n"
#define ERROR_NO_ELEMENT "Klaida! Nepavyko rasti elemento siuo indeksu!\n"
#define ERROR_CANNOT_INSERT "Klaida! Nepavyko iterpti elemento!\n"
#define Item_type int      // Vektoriaus tipas

typedef struct Vector {
    Item_type *items;      // Elementų masyvas
    size_t capacity;       // Vektoriau talpa
    size_t size;          // Vektoriaus elementų skaičius
} vector;

// Funkcija, perskirstanti vektoriaus atmintį
// Jeigu vektorius pasiekia savo talpą, ši funkcija padvigubina talpą
void reallocVector(vector *v, size_t capacity);

// Funkcija, sukurianti vektorių
void initVector(vector *v);

// Funkcija, atlaisvinanti vektoriaus atmintį
void freeVector(vector *v);

// Funkcija, grąžinanti vektoriaus elementų skaičių
size_t getSize(vector *v);

// Funkcija, tikrinanti ar vektorius yra tuščias
bool isEmpty(vector *v);

// Funkcija, tikrinanti ar vektorius elementų skaičius pasiekė savo talpą
bool isFull(vector *v);

// Funkcija, grąžinanti vektoriaus elementus
char* toString(vector *v);

// Funkcija, sukurianti vektoriaus kopiją
void cloneVector(vector *v, vector *dest);

// Funkcija, išvalanti vektorių
void makeEmpty(vector *v);

// Funkcija, pridedanti elementą į vektorių
void addElement(vector *v, Item_type item);

// Funkcija, nustatanti elemento reikšmę pagal indeksą
void setElementAt(vector *v, ssize_t index, Item_type item);

// Funkcija, grąžinanti elementą pagal indeksą
Item_type getElementAt(vector *v, ssize_t index);

// Funkcija, pašalinanti elementą pagal indeksą
void removeElementAt(vector *v, ssize_t index);

// Funkcija, įterpianti elementą į indeksu nurodytą vietą
void insertElementAt(vector *v, ssize_t index, Item_type item);

#endif