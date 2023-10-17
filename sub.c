#include "monty.h"
/**
 * subtracts - subtracts the top element to the second top element.
 * @head: head of the linked list.
 * @cline: line number.
 * Return: nothing.
 */
void subtracts(stack_t **head, unsigned int ln)
{
	int i = 0;
	stack_t *a = NULL;

	a = *head;

	for (; a != NULL; a = a->next, i++);

	if (i < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", ln);
		gvar_free();
		exit(EXIT_FAILURE);
	}

	a = (*head)->next;
	a->n -= (*head)->n;
	remove_top(head, ln);
}
