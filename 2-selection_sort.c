#include "sort.h"

/**
 * selection_sort - sort an array of integers using selection sort
 *
 * @array: the array to sort
 * @size: the size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
unsigned long int i, j;
unsigned long int smallest = 0;
int *swap = NULL;

if (!array || size < 2)
{
return;
}
for (i = 0; i < size; i++)
{
smallest = i;
swap =  malloc(sizeof(int) * 1);
*swap = *(array + i);
for (j = i + 1; j < size; j++)
{
if (*(array + j) < *(array + smallest))
{
smallest = j;
}
}
if (i < smallest)
{
*(array + i) = *(array + smallest);
*(array + smallest) = *swap;
free(swap);
print_array(array, size);
}
else
{
free(swap);
}
}
}
