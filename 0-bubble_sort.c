#include "sort.h"
void temp_swap(int *a, int *b);

/**
 * bubble_sort - sort an array of integer in ascending order
 * @array: the array to order and print
 * @size: size of array to order
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
unsigned int i, j;

if (size <= 1)
{
return;
}

for (i = 0; i < (size - 1); i++)
{
for (j = 1; j < size; j++)
{
if (array[j - 1] > array[j])
{
temp_swap(&array[j - 1], &array[j]);
print_array(array, size);
}
}
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
