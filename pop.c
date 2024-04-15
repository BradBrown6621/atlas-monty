#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!stack || !*stack)
	{
		fprintf(
				stderr,
				"L%d: can't pop an empty stack\n",
				linenumber
				);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	free(current);
	(void)line_number;
}
