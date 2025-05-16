#ifndef QSORT_H
#define QSORT_H

#include <stdlib.h>

/*
 *  swap a with b of size "size"
 */
void swap (void *a, void *b, size_t item_size);
int partition (void *orig_arr, size_t item_size, size_t low, size_t high,
               int (*compare) (const void *, const void *));
void quicksort (void *orig_arr, size_t item_size, size_t low, size_t high,
                int (*compare) (const void *, const void *));
void qsort (void *orig_arr, size_t item_size, size_t arr_size,
            int (*compare) (const void *, const void *));

#endif
