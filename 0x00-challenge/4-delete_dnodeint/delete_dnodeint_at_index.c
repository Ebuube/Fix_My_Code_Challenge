#include "lists.h"
#include <stdlib.h>
#include <stdio.h>	/* test */

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		printf("Loop: p = %u\n", p);	/* test */
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		printf("index out of range: p = %u\tindex = %u\n", p, index);	/* test */
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
	{
		printf("index == zero (%u)\n", index);	/* test */
		printf("(*head) = %p\n", (void *)(*head));	/* test */
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		printf("index != zero (%u)\n", index);	/* test */
		/* (*head)->prev->prev = (*head)->prev; */
		(*head)->prev->next = (*head)->next;
		/* free(*head); */
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		free(*head);
		*head = saved_head;
	}
	return (1);
}
