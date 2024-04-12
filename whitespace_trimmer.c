#include "monty.h"

void whitespace_trimmer(char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == ' ' || src[i] == '\n')
		{
			memmove(&src[i], &src[i] + 1, strlen(src + 1) + 1);
		} else
		{
			if (src[i + 1] == ' ')
			{
				i++;
			}
			i++;
		}
	}
}
