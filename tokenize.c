#include <stdlib.h>
#include <string.h>
#define _POSIX_C_SOURCE 200809L
/**
 * _strdup - duplicates the string and returns a pointer to new string
 * @str: string to be duplicated
 * Return: returns the duplicates the of the string
 *         returns NULL if ERROR
 */
char *_strdup(char *str)
{
	char *dup = NULL;
	int i = 0;

	if (str == NULL)
		return (dup);

	dup = malloc(sizeof(char) * strlen(str) + 1);

	while (str && str[i])
	{
		dup[i] = str[i];
		i++;
	}

	dup[i] = '\0';
	return (dup);
}
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

	strl =_strdup(strn);
	strln = strtok(strl, delim);

	while (strln)
	{
		tokens++;
		strln = strtok(NULL, delim);
	}

	tokens++;
	free(strl);

	*arr = malloc(sizeof(char *) * tokens);
	strd = _strdup(strn);
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
