#include "sort.h"

void node_swap(listint_t *curr, listint_t *insertion, listint_t **head);

/**
 * insertion_sort_list - sort a doubly linked list of integer
 * in ascending order
 * @list: pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
listint_t *current = NULL;
listint_t *insertion = NULL;

if (list == NULL || *list == NULL || (*list)->next == NULL)
{
return;
}

current = (*list)->next;
insertion = current->prev;
while (current != NULL)
{
insertion = current->prev;
while (insertion != NULL && insertion->n > current->n)
{
node_swap(current, insertion, list);
insertion = current->prev;
}
current = current->next;
}
}

/**
* node_swap - swaps two members of a list
*
* @current: current node to be moved at left of insertion
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
