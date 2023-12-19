#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm with Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int partition_index;

    if (low < high)
    {
        partition_index = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, partition_index - 1, size);
        quick_sort_recursive(array, partition_index + 1, high, size);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, i, j, temp;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; ++j)
    {
        if (array[j] <= pivot)
        {
            /* Swap array[i+1] and array[j] */
            ++i;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            /* Print the array after each swap */
            print_array(array, size);
        }
    }

    /* Swap array[i+1] and array[high] (pivot) */
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    /* Print the array after the final swap */
    print_array(array, size);

    return (i + 1);
}
