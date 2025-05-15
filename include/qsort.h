#ifndef QSORT_H
#define QSORT_H

#include <stdlib.h>

/*
 *  swap a with b of size "size"
 */
void swap(void* a, void* b, size_t item_size);
// i = low = 0    i = 1         i = 2           swap(3, i)
// 5 6 2 1 4 3 => 2 6 5 1 4 3 => 2 1 5 6 4 3 => 2 1 3 6 4 5 => qsort on left and right side of pivot 
int partition(void* orig_arr, size_t item_size, size_t low, size_t high, int (*compare)(const void *, const void*));
void quicksort(void* orig_arr, size_t item_size, size_t low, size_t high, int (*compare)(const void *, const void *));
void qsort(void* orig_arr, size_t item_size, size_t arr_size, int (*compare)(const void*, const void*));

#endif
