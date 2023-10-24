#include "sort.h"

void radix_sort(int *array, size_t size);
unsigned int count_sort(int *array, size_t size, unsigned int digit);
unsigned int power_10(unsigned int power);

/**
 * power_10 - calculates a positive power of 10
 * @power: power of 10 to calculate
 *
 * Return: final result
 */
unsigned int power_10(unsigned int power)
{
unsigned int n, result;

result = 1;
for (n = 0; n < power; n++)
{
result *= 10;
}
return (result);
}

/**
 * count_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * @digit: digit to sort
 *
 * Return: 1 if when need to keep sorting, otherwise 0
 */
unsigned int count_sort(int *array, size_t size, unsigned int digit)
{
int i, count[10] = {0};
int *copy = NULL;
size_t j, temp, total = 0;
unsigned int dp_1, dp_2, sort = 0;

dp_2 = power_10(digit - 1);
dp_1 = dp_2 * 10;
copy = malloc(sizeof(int) * size);
if (copy == NULL)
{
exit(1);
}
for (j = 0; j < size; j++)
{
copy[j] = array[j];
if (array[j] / dp_1 != 0)
{
sort = 1;
}
}
for (i = 0; i < 10 ; i++)
{
count[i] = 0;
}
for (j = 0; j < size; j++)
{
count[(array[j] % dp_1) / dp_2] += 1;
}
for (i = 0; i < 10; i++)
{
temp = count[i];
count[i] = total;
total += temp;
}
for (j = 0; j < size; j++)
{
array[count[(copy[j] % dp_1) / dp_2]] = copy[j];
count[(copy[j] % dp_1) / dp_2] += 1;
}
free(copy);
return (sort);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
unsigned int n, sort = 1;

if (array == NULL || size < 2)
{
return;
}

for (n = 1; sort == 1; n++)
{
sort = count_sort(array, size, n);
print_array(array, size);
}
}
