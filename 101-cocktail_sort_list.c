#include "sort.h"

void node_swap(listint_t *current, listint_t *insertion, listint_t **head);
void cocktail_sort_list(listint_t **list);

/**
* cocktail_sort_list - coctail sort in doubly linked list
* @list: doubly linked list to be sorted
*
* Return: nothing
*/

void cocktail_sort_list(listint_t **list)
{
listint_t *current;
listint_t *max = NULL;
listint_t *min = NULL;

if (!list || !(*list) || (*list)->next == NULL)
{
return;
}
current = *list;
do
{
while (current->next)
{
if (current->n > current->next->n)
{
node_swap(current->next, current, list);
}
else
{
current = current->next;
}
}
max = current;
while (current->prev != min)
{
if (current->n < current->prev->n)
{
node_swap(current, current->prev, list);
}
else
{
current = current->prev;
}
}
min = current;
}
while (min != max);
}

/**
* node_swap - swaps two members of a list
*
* @curr: current node to be moved at left of insertion
* @insertion: insertion pointer
* @head: head of list
*/
void node_swap(listint_t *current, listint_t *insertion, listint_t **head)
{
listint_t *swap_1 = current->next;
listint_t *swap_2 = insertion->prev;

if (swap_1 != NULL)
{
swap_1->prev = insertion;
}
if (swap_2 != NULL)
{
swap_2->next = current;
}
current->prev = swap_2;
insertion->next = swap_1;
current->next = insertion;
insertion->prev = current;
if (*head == insertion)
{
*head = current;
}
print_list(*head);
}
