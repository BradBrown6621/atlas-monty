#include "monty.h"

void free_tokens(char ***array)
{
	int i;

	if (!array || !*array)
		return;

	for (i = 0; (*array)[i]; i++)
	{
		printf("token: %s\n", (*array)[i]);
		free((*array)[i]);
	}
	free(*array);
	array = NULL;
}
