#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *a = *stack;
	stack_t *b = (*stack)->next;
	if (!stack || !*stack ||!(*stack)->next)
	{
		fprintf(
				stderr,
				"L%d: can't swap, stack too short\n",
				linenumber
				);
		exit(EXIT_FAILURE);
	}

	if (b->next)
	{
		b->next->prev = b->prev;
	}
	b->prev = NULL;
	a->next = b->next;
	a->prev = b;
	b->next = a;

	*stack = b;
	(void)line_number;
}
