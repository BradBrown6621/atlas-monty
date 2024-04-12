#include "monty.h"

void push(stack_t **head, unsigned int lineArgn)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = lineArgn;
	new->prev = NULL;
	new->next = *head;
	if ((*head) && (*head)->next)
	{
		(*head)->next->prev = new;
	}
	*head = new;
}
