#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *fast;

	if (list == NULL || *list == NULL)
		return;

	temp = (*list)->next;

	while (temp != NULL)
	{
		fast = temp->next;

		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;

			if (temp->next)
				temp->next->prev = temp->prev;

			if (temp->prev->prev)
				temp->prev->prev->next = temp;

			temp->next = temp->prev;

			if (temp->prev->prev)
				temp->prev = temp->prev->prev;
			else
			{
				temp->prev = NULL;
				*list = temp;
			}

			temp->next->prev = temp;

			print_list(*list);
		}
		temp = fast;
	}
}
