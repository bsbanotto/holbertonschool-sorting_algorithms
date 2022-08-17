#include "sort.h"

/**
 * insertion_sort_list - sort DLL in ascending order using insertion
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	int i, len = 0;
	listint_t *temp, *curr;

	if (!list)
		return;

	curr = *list;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	curr = (*list)->next;

	if (len < 2)
		return;

	for (i = 0; i < len - 1; i++)
	{
		temp = curr->next;
		while (curr->prev && curr->n < curr->prev->n)
		{
			list_swap(list, curr);
			print_list(*list);
		}
		curr = temp;
	}
}

/**
 * list_swap - swaps two doubly-linked list nodes
 * @list: list to swap
 * @curr: node to swap with previous node
 */
void list_swap(listint_t **list, listint_t *curr)
{
	listint_t *prevNode = curr->prev;

	curr->prev = NULL;
	if (prevNode->prev)
		curr->prev = prevNode->prev;

	if (curr->next)
		curr->next->prev = prevNode;

	prevNode->next = curr->next;

	curr->next = prevNode;

	if (!prevNode->prev)
		*list = curr;
	if (prevNode->prev)
		prevNode->prev->next = curr;

	prevNode->prev = curr;
}
