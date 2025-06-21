#ifndef ARR_31_03_ARRAYOPERATIONS_H
#define ARR_31_03_ARRAYOPERATIONS_H

void printElements(const int *ptrArray, const int size);

void setAllElements(int *array, const int size);

void setTheElement(int *array, const int size);

int findMaximumValue(const int *array, const int size);

int findMinimumValue(const int *array, const int size);

double calculateAverageValue(const int array[], const int size);

void sortArray(int *array, const int size);

void copyArray(const int *originalArray, int *newArray, const int size);

void previewArrayAsSorted(const int *array, const int size);

double calculateMedianValue(const int *array, const int size);

int saveArrayToFile(const int *array, const int size);

int restoreArrayFromFile(int *array, const int size);

#endif //ARR_31_03_ARRAYOPERATIONS_H