#include "sort.h"

/**
 * merge - sorts a subarray of integers
 * @sub_arr: a subarray of an array of integers to sort
 * @buffer: a buffer to store the sorted subarray
 * @front: the front index of the array
 * @middle: the middle index of the array
 * @back: the back index of the array
 *
 * Return: nothing
 */
void merge(int *sub_arr, int *buffer, size_t front, size_t middle, size_t back)
{
size_t i, j;
size_t k = 0;

printf("Merging...\n[left]: ");
print_array(sub_arr + front, middle - front);

printf("[right]: ");
print_array(sub_arr + middle, back - middle);

for (i = front, j = middle; i < middle && j < back; k++)
{
buffer[k] = (sub_arr[i] < sub_arr[j]) ? sub_arr[i++] : sub_arr[j++];
}
for (; i < middle; i++)
{
buffer[k++] = sub_arr[i];
}
for (; j < back; j++)
{
buffer[k++] = sub_arr[j];
}
for (i = front, k = 0; i < back; i++)
{
sub_arr[i] = buffer[k++];
}

printf("[Done]: ");
print_array(sub_arr + front, back - front);
}

/**
 * split_merge - implement the merge sort algorithm through recursion
 * @sub_arr: a subarray of an array of integers to sort
 * @buffer: a buffer to store the sorted result
 * @front: the front index of the subarray
 * @back: the back index of the subarray
 *
 * Return: nothing
 */
void split_merge(int *sub_arr, int *buffer, size_t front, size_t back)
{
size_t middle;

if (back - front > 1)
{
middle = front + (back - front) / 2;
split_merge(sub_arr, buffer, front, middle);
split_merge(sub_arr, buffer, middle, back);
merge(sub_arr, buffer, front, middle, back);
}
}

/**
 * merge_sort - sort an array of integers in ascending
 * order using the merge sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
int *buffer;

if (array == NULL || size < 2)
{
return;
}

buffer = malloc(sizeof(int) * size);
if (buffer == NULL)
{
return;
}

split_merge(array, buffer, 0, size);

free(buffer);
}
