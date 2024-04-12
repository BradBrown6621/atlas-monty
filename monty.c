#include "monty.h"

unsigned int linenumber = 0;

int main(int argc, char *argv[])
{
	char line[MAXIMUM_CHARS];
	FILE *file = NULL;
	stack_t *stack = NULL;

	char **tokens = NULL;
	unsigned int nTokens = 0;
	unsigned int lineArgn;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
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
		linenumber++;
		whitespace_trimmer(line);
		nTokens = tokenize(&tokens, line, " ");

		if (nTokens > 1)
		{
			lineArgn = (unsigned int)atoi(tokens[1]);
		}

		if (nTokens)
			check_opcodes(tokens[0], lineArgn, &stack);
	}

	fclose(file);
	return (0);
}
