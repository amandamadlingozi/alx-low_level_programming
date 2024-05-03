#include "search_algos.h"
#include <stdio.h>

int main(void) {
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size = sizeof(array) / sizeof(array[0]);

    int index = binary_search(array, size, 5);
    if (index != -1) {
        printf("Value found at index: %d\n", index);
    } else {
        printf("Value not found.\n");
    }
    return 0;
}
