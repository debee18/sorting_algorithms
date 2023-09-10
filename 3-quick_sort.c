#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array && size > 1)
        lomuto_partition(array, size, 0, size - 1);
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick Sort
 * @array: The array to be partitioned
 * @size: Number of elements in the array
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 */
void lomuto_partition(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int pivot = array[high];
        int i = low - 1;
        int j;

        for (j = low; j <= high - 1; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                if (i != j)
                {
                    swap(&array[i], &array[j]);
                    print_array(array, size);
                }
            }
        }

        if (i + 1 != high)
        {
            swap(&array[i + 1], &array[high]);
            print_array(array, size);
        }

        lomuto_partition(array, size, low, i);
        lomuto_partition(array, size, i + 2, high);
    }
}

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

