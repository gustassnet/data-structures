# Vektoriaus (Vector) Implementacija C kalba

## Įvadas

Šiame dokumente aprašoma vektoriaus (dynamic array) realizacija C kalba. Pateikiamos pagrindinės funkcijos, jų aprašymas ir naudojimas, taip pat paaiškinama, kaip modifikuoti kodą, kad būtų palaikomi įvairūs duomenų tipai.

## Funkcijų aprašymas

### 1. `void initVector(vector *v, size_t capacity)`

**Aprašymas:** Sukuria vektorių su nurodyta pradine talpa.  
**Naudojimas:**

```c
vector v;
initVector(&v, 10);  // Sukuriama vektorius su 10 elementų talpa
```

### 2. `void freeVector(vector *v)`

**Aprašymas:** Atlaisvina visą vektoriaus užimtą atmintį.  
**Naudojimas:**

```c
freeVector(&v);
```

### 3. `int getSize(vector *v)`

**Aprašymas:** Grąžina vektoriaus elementų skaičių.<br>
**Naudojimas:**

```c
printf("Vektoriaus dydis: %d\n", getSize(&v));
```

### 4. `bool isEmpty(vector *v)`

**Aprašymas:** Patikrina, ar vektorius yra tuščias. Grąžina true, jei vektorius tuščias, priešingu atveju – false.
<br>
**Naudojimas:**

```c
if (isEmpty(&v)) {
    printf("Vektorius tuščias\n");
}
```

### 5. `bool isFull(vector *v)`

**Aprašymas:** Patikrina, ar vektorius yra pilnas. Grąžina true, jei vektorius pilnas, priešingu atveju – false.
<br>
**Naudojimas:**

```c
if (isFull(&v)) {
    printf("Vektorius pilnas\n");
}
```

### 6. `char* toString(vector *v)`

**Aprašymas:** Grąžina visus vektoriaus elementus.
<br>
**Naudojimas:**

```c
toString(&v);
```

### 7. `void cloneVector(vector *v, vector *dest)`

**Aprašymas:** Sukuria vektoriaus kopiją.<br>
**Naudojimas:**

```c
cloneVector(&v1, &v2);  // v1 vektoriaus elementai nukopijuojami į v2 vektorių
```

### 8. `void makeEmpty(vector *v)`

**Aprašymas:** Pašalina visus vektoriaus elementus.<br>
**Naudojimas:**

```c
makeEmpty(&v);
```

### 9. `void addElement(vector *v, Item_type item)`

**Aprašymas:** Prideda naują elementą į vektorių. Jei vektorius pasiekia savo talpą, jis automatiškai padvigubina savo talpą.<br>
**Naudojimas:**

```c
addElement(&v, 10);
addElement(&v, 20);
```

### 10. `void setElementAt(vector *v, size_t index, Item_type item)`

**Aprašymas:** Nustato elementą reikšmę pagal nurodytą indeksą. Jei indeksas yra neteisingas, nieko nedaro.<br>
**Naudojimas:**

```c
setElementAt(&v, 0, 30);
```

### 11. `Item_type getElementAt(vector *v, size_t index)`

**Aprašymas:** Grąžina elementą pagal nurodytą indeksą. <br>
**Naudojimas:**

```c
printf("Elementas: %d\n", getElementAt(&v, 0));
```

### 12. `void removeElementAt(vector *v, size_t index)`

**Aprašymas:** Pašalina elementą pagal nurodytą indeksą ir pertvarko likusius elementus. <br>
**Naudojimas:**

```c
removeElementAt(&v, 1);
```

### 13. `void insertElementAt(vector *v, size_t index, Item_type item)`

**Aprašymas:** Įterpia elementą į nurodytą vietą vektoriuje. Jei vektorius pasiekia savo talpą, jis automatiškai padvigubina savo talpą. <br>
**Naudojimas:**

```c
insertElementAt(&v, 1, 15);
```

## Kaip pritaikyti kodą skirtingiems duomenų tipams

Šiuo metu vektorius saugo sveikojo (`int`) tipo skaičius. Norint, kad priimtų kitus duomenų tipus reikia modifikuoti:

1. **Pakeisti `#define Item_type` tipą:**

```c
#define Item_type int   // Keisti int į norimą tipą (pvz.: double)
```

2. **Atnaujinti `sprintf` formatavimo specifikatorius:**

- `%d` → `%lf` (`double` tipui)
