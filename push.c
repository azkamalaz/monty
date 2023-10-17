#include "monty.h"
/**
 * add_to_stack - add element to stack.
 * @h: head of linked list.
 * @ln: line number.
 * Return: nothing.
 */
void add_to_stack(stack_t **h, unsigned int ln)
{
	int i, j;

	if (!gvar.arg)
	{
		dprintf(2, "L%u: ", ln);
		dprintf(2, "usage: push integer\n");
		gvar_free();
		exit(EXIT_FAILURE);
	}

	for (j = 0; gvar.arg[j] != '\0'; j++)
	{
		if (!isdigit(gvar.arg[j]) && gvar.arg[j] != '-')
		{
			dprintf(2, "L%u: ", ln);
			dprintf(2, "usage: push integer\n");
			gvar_free();
			exit(EXIT_FAILURE);
		}
	}

	i = atoi(gvar.arg);

	if (gvar.s_or_q == 1)
		add_node(h, i);
	else
		add_node_end(h, i);
}
