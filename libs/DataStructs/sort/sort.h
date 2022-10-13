#ifndef ADSLABS_SORT_H
#define ADSLABS_SORT_H
#include <stdio.h>

void swap(int *a, int *b);

//Сортировка включением
void insertionSort(int *a, const size_t size);

//Сортировка выбором
void selectionSort(int *a, const size_t size);

//Сортировка обменом
void bubbleSort(int *a, const size_t size);

//Сортировка обменом+
void bubbleSortPlus(int *a, const size_t size);

//Сортировка обменом++
void bubbleSortPlusPlus(int *a, const size_t size);

//Сортировка Шелла
void shellSort(int *a, size_t size);

size_t split(size_t left, size_t right, int x);

//Сортировка Хоара
void qSort(int *a, const size_t size);

//Сортировка Пирамидальная

#include "sort.c"
#endif //ADSLABS_SORT_H
