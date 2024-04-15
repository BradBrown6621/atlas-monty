#include "monty.h"

unsigned int linenumber = 0;

int main(int argc, char *argv[])
{
	char line[MAXIMUM_CHARS];
	FILE *file = NULL;
	stack_t *stack = NULL;

	char **tokens = NULL;
	unsigned int nTokens = 0;
	int lineArgn, flag;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		lineArgn = -1;
		flag = 1;
		linenumber++;
		tokens = NULL;
		whitespace_trimmer(line);
		nTokens = tokenize(&tokens, line, " ");

		if (nTokens > 1 && tokens[1])
		{
			lineArgn = atoi(tokens[1]);
			flag = 0;
		}

		if (nTokens)
		{
			check_opcodes(tokens, lineArgn, &stack, flag);
		}

		free_tokens(&tokens);
	}

	free_stack(&stack);
	fclose(file);
	return (0);
}
