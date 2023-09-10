#ifndef SORT_H
#define SORT_H

#include <stddef.h> /* Include the necessary header for 'size_t' */
#include <stdbool.h> /* Include the necessary header for 'bool' */

/* Function prototypes */
void bubble_sort(int *array, size_t size);

/* Provided print_array function */
void print_array(const int *array, size_t size);

/* Selection sort prototypes */
void selection_sort(int *array, size_t size);

/*Prototypes for quick_sort, lomuto_partition, and swap*/
void quick_sort(int *array, size_t size);
void lomuto_partition(int *array, size_t size, int low, int high);
void swap(int *a, int *b);

/*Prototypes for shell sort*/
void shell_sort(int *array, size_t size);

#endif /* SORT_H */

