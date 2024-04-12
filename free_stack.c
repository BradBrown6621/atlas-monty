#include "monty.h"

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		current->next = NULL;
		current->prev = NULL;
		free(current);
		current = next;
	}

	*stack = NULL;
}
