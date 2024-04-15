#include "monty.h"

void check_opcodes(char **args, int line_number, stack_t **head, int flag)
{
	extern unsigned int linenumber;
	int i;
	char *opcode = args[0];

	instruction_t opcodesNoArgs[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	instruction_t opcodes[] = {
		{"push", push},
		{NULL, NULL}
	};

	for (i = 0; opcodesNoArgs[i].f != NULL; i++)
	{
		if (!strcmp(opcode, opcodesNoArgs[i].opcode))
		{
			opcodesNoArgs[i].f(head, (unsigned int)line_number);
			return;
		}
	}
	
	for (i = 0; opcodes[i].f != NULL; i++)
	{
		if (!strcmp(opcode, opcodes[i].opcode))
		{
			if (args[1] == NULL || flag)
			{
				fprintf(
						stderr,
						"L%d: usage: %s integer\n",
						linenumber,
						opcode);
				exit(EXIT_FAILURE);
			}
			opcodes[i].f(head, (unsigned int)line_number);
			return;
		}
	}
	
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", linenumber, opcode);
		exit(EXIT_FAILURE);
	}
}
