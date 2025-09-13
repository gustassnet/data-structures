# Eilės (Queue) Implementacija C kalba

## Įvadas

Šiame dokumente aprašoma eilės (linked list) realizacija C kalba. Pateikiamos pagrindinės funkcijos, jų aprašymas ir naudojimas, taip pat paaiškinama, kaip modifikuoti kodą, kad būtų palaikomi įvairūs duomenų tipai.

## Funkcijų aprašymas

### 1. `void initQueue(Queue *q)`

**Aprašymas:** Sukuria eilę.  
**Naudojimas:**

```c
Queue q;
initQueue(&q);
```


### 2. `size_t size(Queue *q);`

**Aprašymas:** Grąžina eilės elementų skaičių.<br>
**Naudojimas:**

```c
printf("Eilės dydis: %d\n", size(&q));
```


### 3. `bool isEmpty(Queue *q)`

**Aprašymas:** Patikrina, ar eilė yra tuščia. Grąžina true, jei eilė tuščia, priešingu atveju – false.
<br>
**Naudojimas:**

```c
if (isEmpty(&q)) {
    printf("Eilė tuščia\n");
}
```


### 4. `void enqueue(Queue *q, Item_type item)`

**Aprašymas:** Prideda nurodyta elementą į eilės galą
<br>
**Naudojimas:**

```c
enqueue(&q, 1);
```


### 5. `Item_type dequeue(Queue *q)`

**Aprašymas:** Grąžina ir pašalina eilės seniausią elementą
<br>
**Naudojimas:**

```c
printf("%d", dequeue(&q));
```


### 6. `Item_type front(Queue *q)`

**Aprašymas:** Grąžina eilės seniausią elementą
<br>
**Naudojimas:**

```c
printf("%d", front(&q));
```


### 7. `Item_type back(Queue *q)`

**Aprašymas:** Grąžina eilės naujausią elementą
<br>
**Naudojimas:**

```c
printf("%d", back(&q));
```


### 8. `bool contains(Queue *q, Item_type item)`

**Aprašymas:** Patikrina, ar eilė turi nurodytą elementą. Grąžina true arba false.
<br>
**Naudojimas:**

```c
Item_type item = 10;
if (contains(&q, item)) {
    printf("Eilė turi elementa: %d", item);
}
```


### 9. `void clearQueue(Queue *q)`

**Aprašymas:** Pašalina visus eilės elementus.
<br>
**Naudojimas:**

```c
clearQueue(&q);
```


### 10. `void printQueue(Queue *q)`

**Aprašymas:** Atspausdina visus eilės elementus.
<br>
**Naudojimas:**

```c
printQueue(&q);
```


### 11. `char* toString(Queue *q)`

**Aprašymas:** Grąžina visus eilės elementus.
<br>
**Naudojimas:**

```c
toString(&q);
```


## Kaip pritaikyti kodą skirtingiems duomenų tipams

Šiuo metu eilė saugo sveikojo (`int`) tipo skaičius. Norint, kad priimtų kitus duomenų tipus reikia modifikuoti:

1. **Pakeisti `#define Item_type` tipą:**

```c
typedef int Item_type;   // Keisti int į norimą tipą (pvz.: double)
```

2. **Atnaujinti `sprintf` formatavimo specifikatorius:**

- `%d` → `%f` (`double` tipui)
