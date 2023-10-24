#include "sort.h"

long int partition(int *array, long int low, long int high, size_t size);
void sort(int *array,  long int low,  long int high, size_t size);
void quick_sort(int *array, size_t size);
void temp_swap(int *a, int *b);

/**
 * quick_sort - sort an array of integers using quick_sort
 * lomuto implementation with pivot in last element of partition
 * @array: array to sort
 * @size: the size of the array to sort
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
{
return;
}

sort(array, 0, size - 1, size);
}

/**
 * sort - recursion to implement the quicksort (Lomuto version)
 * @array: the array to sort
 * @low: where begins the partition
 * @high: where ends the partition
 * @size: the total size of array to be printed
 */
void sort(int *array,  long int low,  long int high, size_t size)
{
long int pivot = 0;

if (low < high)
{
pivot = partition(array, low, high, size);
}
else
{
return;
}

sort(array, low, pivot - 1, size);
sort(array, pivot + 1, high, size);

}

/**
 * partition - partition elements in two
 * @array: the array to be partitioned
 * @low: where the partitions begin and is less than right
 * @high: where the partitions end
 * @size: total lenght of the array
 * Return: the pivot index of the partition
 */
long int partition(int *array, long int low, long int high, size_t size)
{
long int pivot = 0, i = 0, j = 0;

pivot = high;

i = low - 1;

for (j = low; j < high; j++)
{
if (*(array + j) < *(array + pivot))
{
i++;
if (i != j)
{
temp_swap(&array[i], &array[j]);
print_array(array, size);
printf("i:%ld-j:%ld\n", i, j);
}
}
}
if (*(array + high) < *(array + i + 1))
{
temp_swap(&array[high], &array[i + 1]);
print_array(array, size);
printf("high:%ld, i+1:%ld\n", high, i + 1);
}

return (i + 1);
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
