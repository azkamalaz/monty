#include "monty.h"
/**
 * multiplies - multiplies the top element to the second top element.
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void multiplies(stack_t **head, unsigned int ln)
{
	int i = 0;
	stack_t *a = NULL;

	a = *head;

	for (; a != NULL; a = a->next, i++)
	;

	if (i < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", ln);
		gvar_free();
		exit(EXIT_FAILURE);
	}

	a = (*head)->next;
	a->n *= (*head)->n;
	remove_top(head, ln);
}
