#include <stdlib.h>
/**
 * tokenize - tokenize the string and save them in an arrray
 * @arr: array to be modifieda and save tokens
 * @strn: string to be tokenized
 * @delim: delimeter used to tokenize a string
 * Return: returns size of the string array
*/
int tokenize(char ***arr, char *strn, char *delim)
{
	char *str = NULL, *strd = NULL, *strl = NULL, *strln = NULL;
	int tokens = 0, i = 0;

	if (strn == NULL)
		return (tokens);

	strl = strdup(strn);
	strln = strtok(strl, delim);

	while (strln)
	{
		tokens++;
		strln = strtok(NULL, delim);
	}

	tokens++;
	free(strl);

	*arr = malloc(sizeof(char *) * tokens);
	strd = strdup(strn);
	str = strtok(strd, delim);

	while (str)
	{
		(*arr)[i] = malloc(sizeof(char) * strlen(str) + 1);
		strcpy((*arr)[i], str);
		str = strtok(NULL, delim);
		i++;
	}

	(*arr)[i] = NULL;
	free(strd);

	return (tokens);
}
