#include "sort.h"

/**
 * insertion_sort_list - sort DLL in ascending order using insertion
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	int i, len = 0;
	listint_t *temp, *curr = *list;

	while (curr)
	{
		len++;
		curr = curr->next;
	}
	curr = *list;

	if (len < 2)
		return;

	for (i = 0; i < len; i++)
	{
		curr = curr->next;
		temp = curr->next;
		while(curr->n < curr->prev->n)
		{
			list_swap(*list, curr);
			print_list(*list);
		}
		curr = temp->prev;
	}
}

/**
 * list_swap - swaps two doubly-linked list nodes
 * @list: list to swap
 * @curr: node to swap with previous node
 */
void list_swap(listint_t *list, listint_t *curr)
{
	listint_t *prevNode = curr->prev;

	if (prevNode->prev == NULL && curr->next)
	{
		curr->prev = NULL;
		curr->next->prev = prevNode;
		prevNode->next = curr->next;
		curr->next = prevNode;
		list = curr;
		prevNode->prev = curr;
		return;
	}
	if (prevNode->prev && curr->next)
	{
		curr->prev = prevNode->prev;
		curr->next->prev = prevNode;
		prevNode->next = curr->next;
		curr->next = prevNode;
		prevNode->prev->next = curr;
		prevNode->prev = curr;
	}
	if (curr->next == NULL && prevNode->prev)
	{
		curr->prev = prevNode->prev;
		prevNode->next = curr->next;
		curr->next = prevNode;
		prevNode->prev->next = curr;
		prevNode->prev = curr;
	}
	if (list->n > list->next->n)
	{
		curr->prev = prevNode->prev;
		prevNode->next = curr->next;
		curr->next = prevNode;
		list = curr;
		prevNode->prev = curr;
	}
}
