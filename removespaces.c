#include <stdbool.h>
#include <string.h>

/**
 * _isspace - Custom implementation of isspace function
 * @c: The character to check for white-space
 *
 * Return: true if the character is white-space, false otherwise.
 */
bool _isspace(char c)
{
	return (c == ' ' || c == '\t');
}
/**
 * remove_spaces - remove all white spaces
 * @string: string to remove white spaces
 *
*/
void remove_spaces(char *string)
{

	int length = strlen(string);
	int j = 0, i = 0;

	for (; i < length; i++)
	{
		if (string[i] != ' ')
		{
			string[j] = string[i];
			j++;
		}
	}

	string[j] = '\0';
}

/**
 * remove_extra_spaces - remove extra white spaces
 * @input: string to remove white spaces
 *
*/
void remove_extra_spaces(char *input)
{
	char *output = input;
	int isSpace = 0;

	while (input && *input)
	{
		if (_isspace(*input))
		{
			if (!isSpace)
			{
				*output++ = ' ';
				isSpace = 1;
			}
		}
		else
		{
			*output++ = *input;
			isSpace = 0;
		}

		input++;
	}

	if (output)
	{
		*output = '\0';
	}

}

/**
 * remove_emptyspaces - remove white spaces
 * @str: string to remove white spaces
 *
*/
void remove_emptyspaces(char *str)
{
	int i = 0, count = 0;

	if (str)
	{
		i = strlen(str) - 1;
	}


	while (i >= 0)
	{
	  if ((str && str[i] == ' ') ||
	      (str[i] == '\t'))
			i--;
		else
			break;
	}

	if ((str))
	{
	       str[i + 1] = '\0';
	}


while ((str && str[count] == ' ' )||
       (str[count] == '\t'))
		count++;

	if (count != 0)
	{
		i = 0;

		while (str[i + count] != '\0')
		{
			str[i] = str[i + count];
			i++;
		}
		str[i] = '\0';
	}
	remove_extra_spaces(str);
}
