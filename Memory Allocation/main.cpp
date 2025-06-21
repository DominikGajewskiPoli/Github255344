#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, aSize;
    int *randomNums;
    time_t t;
    double total = 0;
    int biggest, smallest;
    float average;

    srand(time(&t));
    printf("Ile liczb losowych chcesz zapisac w tablicy? ");
    scanf(" %d", &aSize);


    randomNums = (int *) malloc(aSize * sizeof(int));
    printf("Proba alokacji %ld bajtow w pamieci...\n\n", aSize * sizeof(int));


    if (!randomNums) {
        printf("Nie udało się alokować tablicy!\n");
        exit(1);
    }


    for (i = 0; i < aSize; i++) {
        randomNums[i] = (rand() % 500) + 1;
    }

    biggest = 0;
    smallest = 500;
    for (i = 0; i < aSize; i++) {
        total += randomNums[i];
        if (randomNums[i] > biggest) {
            biggest = randomNums[i];
        }
        if (randomNums[i] < smallest) {
            smallest = randomNums[i];
        }
    }
    average = ((float) total) / ((float) aSize);

    printf("Najwieksza liczba: %d.\n", biggest);
    printf("Najmniejsza liczba: %d.\n", smallest);
    printf("Srednia: %.2f.\n", average);
    free(randomNums);

    return (0);
}