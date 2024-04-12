#include "monty.h"

void check_opcodes(char *opcode, unsigned int linenumber, stack_t **head)
{
	int i;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].f != NULL; i++)
	{
		if (!strcmp(opcode, opcodes[i].opcode))
		{
			opcodes[i].f(head, linenumber);
			return;
		}
	}
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", linenumber, opcode);
		exit(EXIT_FAILURE);
	}
}
