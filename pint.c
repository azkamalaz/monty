#include "monty.h"
/**
 * print_at_top - the value at the top of the stack.
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void print_at_top(stack_t **head, unsigned int ln)
{
	(void)ln;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", ln);
		dprintf(2, "can't pint, stack empty\n");
		gvar_free();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}