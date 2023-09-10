#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm with the Knuth sequence.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1;
    int tmp, i, j;

    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (i = gap; i < (int)size; i++)
        {
            tmp = array[i];
            j = i;

            while (j >= (int)gap && array[j - gap] > tmp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = tmp;
        }

        print_array(array, size);
        gap = (gap - 1) / 3;
    }
}

