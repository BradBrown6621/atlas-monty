#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack)
	{
		return;
	}
	if (!*stack)
	{
		return;
	}
	current = *stack;
	while (current)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
	(void)line_number;
}	
