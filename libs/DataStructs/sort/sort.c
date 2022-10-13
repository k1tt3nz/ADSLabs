#include "sort.h"

#include <stdbool.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int *a, const size_t size){
    for (size_t i = 1; i < size - 1; ++i) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t){
            a[j] = a[j-1];
            j--;
        }
        a[j] = t;
    }
}


void selectionSort(int *a, const size_t size){
    for (size_t i = 0; i < size - 1; ++i) {
        int minPos = i;
        for (size_t j = i + 1; j < size - 1; ++j)
            if(a[j] < a[minPos])
                minPos = j;
        swap(&a[i],&a[minPos]);
    }
}

void bubbleSort(int *a, const size_t size){
    for (size_t i = 0; i < size -1; ++i) {
        for (size_t j = size - 1; j > i; --j) {
            if(a[j - 1] > a[j])
                swap(&a[j - 1],&a[j]);
        }
    }
}

void bubbleSortPlus(int *a, const size_t size){
    for (size_t i = 0; i < size -1; ++i) {
        bool isTransposition = false;
        for (size_t j = size - 1; j > i; --j) {
            if(a[j - 1] > a[j]){
                swap(&a[j - 1],&a[j]);
                isTransposition = true;
            }
        }

        if(!isTransposition)
            return;
    }
}

void bubbleSortPlusPlus(int *a, const size_t size){
    for (size_t i = 0; i < size -1; ++i) {
        int t = a[i];
        for (size_t j = size - 1; j > i; --j) {
            if(a[j - 1] == t)
                break;

            if(a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j]);
                t = a[j - 1];
            }
        }
    }
}

void shellSort(int *a, size_t size) {
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && a[j] > a[j + s]; j -= s) {
                int temp = a[j];
                a[j] = a[j + s];
                a[j + s] = temp;
            }
        }
    }
}

// Доделать
size_t split(size_t left, size_t right, int x){
    size_t iWrite = left;
    for (size_t iRead = left; iRead < right - 1; ++iRead) {

    }
}

void qSort(int *a, const size_t size);