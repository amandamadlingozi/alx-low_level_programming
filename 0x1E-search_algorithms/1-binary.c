#include "search_algos.h"

/**
 * print_array - Helper function to print the array from `left` to `right`
 * @array: Pointer to the array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;
    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 * Return: The index where value is located or -1 
 * if not found or array is NULL.
 */
int binary_search(int *array, size_t size, int value)
{
    size_t left = 0, right = size - 1, mid;
    
    if (!array)
        return (-1);
    
    while (left <= right)
    {
        print_array(array, left, right);
        mid = left + (right - left) / 2;
        
        if (array[mid] == value)
            return (mid);
        else if (array[mid] > value)
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    return (-1);
}
