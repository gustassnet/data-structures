# Grafo medis

## Aprašymas
Ši programa realizuoja algoritmą, kuris iš duoto neorientuoto grafo suformuoja medį, naudojant paieškos į plotį (BFS) metodą. Grafo duomenys saugomi kaimynystės matricą naudojančioje duomenų struktūroje.

## Tikslas
Duotas grafas gali turėti ciklų, tačiau medis – tai grafas be ciklų. Pritaikius BFS algoritmą nuo pasirinktos pradinės viršūnės, suformuojamas medis (t.y. n - 1 briaunų skaičius, leidžiantis pasiekti visas viršūnes).

## Programos veikimas
- Iš failo nuskaitoma grafo kaimynystės matrica.
- Naudojant BFS algoritmą, nuo pasirinktos pradinės viršūnės (pvz., viršūnė 2) sudaromas medis.
- Rezultatas – medis pateikiamas kaip sąrašas ryšių tarp viršūnių.