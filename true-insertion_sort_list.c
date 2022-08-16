#include "sort.h"

/**
 * insertion_sort_list - sort DLL in ascending order using insertion
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	int i, len = 0;
	listint_t *temp, *prevNode, *curr = *list;

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
		if (curr->n < curr->prev->n)
		{
			temp = curr;
			prevNode = temp->prev;
			while (prevNode && temp->n < prevNode->n)
				prevNode = prevNode->prev;

			if (!prevNode)
			{
				move_to_head(*list, temp);
				print_list(*list);
				continue;
			}
			move_to_loc(temp, prevNode);

			print_list(*list);
		}
	}
}

void move_to_loc(listint_t *nodeToMove, listint_t *prevNode)
{
	nodeToMove->next->prev = nodeToMove->prev;
	nodeToMove->prev = prevNode;
	nodeToMove->next->prev->next = nodeToMove->next;
	nodeToMove->next = prevNode->next;
	prevNode->next->prev = nodeToMove;
	prevNode->next = nodeToMove;
}

void move_to_head(listint_t *head, listint_t *nodeToMove)
{
	nodeToMove->next->prev = nodeToMove->prev;
	nodeToMove->prev = NULL;
	nodeToMove->next->prev->next = nodeToMove->next;
	nodeToMove->next = head;
	head->prev = nodeToMove;
	head = nodeToMove;
}

/**
 * list_swap - swaps two doubly-linked list nodes
 * @a: node to swap with next node
 */
void list_swap(listint_t *a)
{
	listint_t *b = a->next;

	b->prev = a->prev;
	a->prev->next = b;
	a->next = b->next;
	a->prev = b;
	b->next = a;
	a->next->prev = a;
}
