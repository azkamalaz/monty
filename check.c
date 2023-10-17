#include "monty.h"
/**
 * _check - check if file exists and can be open.
 * @argc: arg count.
 * @argv: arg vector.
 * Return: file descriptor.
 */
FILE *_check(int argc, char *argv[]) 
{
	FILE *filed;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filed = fopen(argv[1], "r");

	if (filed == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (filed);
}