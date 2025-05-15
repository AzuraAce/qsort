#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qsort.h"

// swap a with b of size "size"
void swap
(void* a, void* b, size_t item_size)
{
    char tmp[item_size];
    memcpy(tmp, a, item_size);
    memcpy(a, b, item_size);
    memcpy(b, tmp, item_size);
}

int partition
(void* orig_arr, size_t item_size, size_t low, size_t high,
 int (*compare)(const void *, const void*))
{
    int i = low;
    char* arr = (char*)orig_arr;
    void* pivot = arr + high * item_size;

    for(size_t j = low; j < high; j++){
        void* elem = arr + j * item_size;
        // Check if elem is smaller than pivot
        if(compare(elem, pivot) < 0){
            void* low_elem = arr + i * item_size;
            swap(low_elem, elem, item_size);
            i++;
        }
    }

    // place pivot into spot,
    // where all elements left are less and
    // right are greater
    swap(arr + i * item_size, pivot, item_size);
    return i;
}

void quicksort
(void* orig_arr, size_t item_size, size_t low, size_t high,
 int (*compare)(const void *, const void *))
{
    if(low < high){
        int p = partition(orig_arr, item_size, low, high, compare);
        if (p > 0)
            // sort left side of pivot
            quicksort(orig_arr, item_size, low, p - 1, compare);
        // sort right side of pivot
        quicksort(orig_arr, item_size, p + 1, high, compare);
    }
}

void qsort
(void* orig_arr, size_t item_size, size_t arr_size,
 int (*compare)(const void*, const void*))
{
    quicksort(orig_arr, item_size, 0, arr_size - 1, compare);
}
