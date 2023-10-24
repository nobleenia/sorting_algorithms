#include "sort.h"

void temp_swap(int *a, int *b);
void shell_sort(int *array, size_t size);

/**
 * shell_sort - sort an array of integers in ascending
 * order using the shell sort algorithm
 * @array: an array of integers
 * @size: size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;

if (array == NULL || size < 2)
{
return;
}

for (gap = 1; gap < (size / 3);)
{
gap = gap * 3 + 1;
}

for (; gap >= 1; gap /= 3)
{
for (i = gap; i < size; i++)
{
j = i;
while (j >= gap && array[j - gap] > array[j])
{
temp_swap(array + j, array + (j - gap));
j -= gap;
}
}
print_array(array, size);
}
}

/**
 * temp_swap - swap two pointers to integer
 *
 * @a: first int pointer
 * @b: second int pointer
 */
void temp_swap(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;
}
