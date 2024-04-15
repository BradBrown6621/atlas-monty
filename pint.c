#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(
				stderr,
				"L%d: can't pint, stack empty\n",
				linenumber
				);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
	(void)line_number;
}
