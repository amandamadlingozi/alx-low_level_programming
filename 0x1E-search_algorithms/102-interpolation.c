#include "search_algos.h"
#include <stdio.h> /* Make sure stdio.h is included for printf */

/**
  * interpolation_search - Searches for a value in a sorted array
  *                        of integers using interpolation search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  *
  * Description: Prints a value every time it is compared in the array.
  */
int interpolation_search(int *array, size_t size, int value)
{
    size_t i, l = 0, r = size - 1;

    if (array == NULL)
        return (-1);

    while (l <= r && value >= array[l] && value <= array[r])
    {
        /* Avoid division by zero */
        if (array[l] == array[r]) {
            if (array[l] == value) return (int)l;
            return -1;
        }

        i = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));

        /* Ensure i is within bounds before accessing array[i] */
        if (i >= size) {
            printf("Value checked array[%lu] is out of range\n", i);
            break;
        }

        printf("Value checked array[%lu] = [%d]\n", i, array[i]);

        if (array[i] == value)
            return (int)i;
        if (array[i] < value)
            l = i + 1;
        else
            r = i - 1;
    }

    return -1;
}
