#include "sort.h"

void heap_sort(int *array, size_t size);
void make_heap(int *array, size_t size);
void fix_heap(int *array, size_t root, size_t end, size_t size);

/**
 * fix_heap - fixes a heap
 * @array: the heap to be fixed
 * @root: root of heap
 * @end: last index of the heap
 * @size: size of the array
 *
 * Return: nothing
 */
void fix_heap(int *array, size_t root, size_t end, size_t size)
{
size_t left, right, swap;
int temp;

while ((left = (2 * root) + 1) <= end)
{
swap = root;
right = left + 1;
if (array[swap] < array[left])
{
swap = left;
}
if (right <= end && array[swap] < array[right])
{
swap = right;
}
if (swap == root)
{
return;
}

temp = array[root];
array[root] = array[swap];
array[swap] = temp;
print_array(array, size);
root = swap;
}
}

/**
 * make_heap - makes a heap from an unsorted array
 * @array: array to turn into a heap
 * @size: size of the array
 * 
 * Return: void
 */
void make_heap(int *array, size_t size)
{
size_t origin;

for (origin = ((size - 1) - 1) / 2; 1; origin--)
{
fix_heap(array, origin, size - 1, size);
if (origin == 0)
{
break;
}
}
}

/**
 * heap_sort - sorts an array of ints in ascending order w/ the Heap sort algo
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
size_t end;
int temp;

if (array == NULL || size < 2)
{
return;
}
make_heap(array, size);
end = size - 1;
while (end > 0)
{
temp = array[end];
array[end] = array[0];
array[0] = temp;
print_array(array, size);
end--;
fix_heap(array, 0, end, size);
}
}
