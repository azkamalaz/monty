#include "monty.h"
/**
 * _strcmp - comparing two strings.
 * @str1: type str compared
 * @str2: type str compared
 * Return: 0 if str1 and str2 are equals.
 */
int _strcmp(char *str1, char *str2) 
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i]; i++)
		;
	if (str1[i] > str2[i])
		return (1);
	if (str1[i] < str2[i])
		return (-1);
	return (0);
}
/**
 * find_char - find char  in string.
 * @str: string to find.
 * @chars: char to find.
 * Return: 1 if success 0 if faillure.
 */
int find_char(char *str, char chars) 
{
	int n = 0;

	while (str[n] != '\0')
	{
		if (str[n] == chars)
		{
			break;
		}
		n++;
	}
	if (str[n] == chars)
		return (1);
	else
		return (0);
}

/**
 * str_token - cut string into tokens.
 * @str: string to cut.
 * @delim: delimiters.
 * Return: first part.
 */
char *str_token(char *str, char *delim) 
{
	static char *a;
	int i = 0, j = 0;

	if (!str)
		str = a;
	while (str[i] != '\0')
	{
		if (find_char(delim, str[i]) == 0 && str[i + 1] == '\0')
		{
			a = str + i + 1;
			*a = '\0';
			str = str + j;
			return (str);
		}
		else if (find_char(delim, str[i]) == 0 && find_char(delim, str[i + 1]) == 0)
			i++;
		else if (find_char(delim, str[i]) == 0 && find_char(delim, str[i + 1]) == 1)
		{
			a = str + i + 1;
			*a = '\0';
			a++;
			str = str + j;
			return (str);
		}
		else if (find_char(delim, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
