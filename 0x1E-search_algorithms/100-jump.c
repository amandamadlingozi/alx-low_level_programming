#include "search_algos.h"

int jump_search(int *array, size_t size, int value)
{
    size_t i, jump, step;

    if (array == NULL || size == 0)
        return (-1);

    step = (size_t)sqrt(size);
    for (i = jump = 0; jump < size && array[jump] < value;)
    {
        printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
        i = jump;
        jump += step;
    }

    if (jump >= size)  /* Prevent going out of bounds */
        jump = size - 1;

    printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

    for (; i <= jump && i < size; i++)
    {
        printf("Value checked array[%ld] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return (int)i;  /* Return as soon as value is found */
    }

    return -1;  /* Return -1 if value not found within the range */
}
