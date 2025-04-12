#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion Sort algorithm.
 *
 * @list: The doubly linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert_pos, *temp;

	if (!list || !(*list) || !(*list)->next)
	return;

	current = (*list)->next;
	while (current)
	{
		insert_pos = current;
		while (insert_pos->prev && insert_pos->n < insert_pos->prev->n)
		{
			temp = insert_pos->prev;
			if (temp->prev)
				temp->prev->next = insert_pos;
			if (insert_pos->next)
				insert_pos->next->prev = temp;

			insert_pos->prev = temp->prev;
			temp->next = insert_pos->next;
			insert_pos->next = temp;
			temp->prev = insert_pos;

			if (!insert_pos->prev)
				*list = insert_pos;

			print_list(*list);
		}
	current = current->next;
	}
}
