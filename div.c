#include "monty.h"
/**
 * divides - divides the second element by the top element.
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void divides(stack_t **head, unsigned int ln)
{
	int i = 0;
	stack_t *a = NULL;

	a = *head;

	for (; a != NULL; a = a->next, i++);

	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", ln);
		gvar_free();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", ln);
		gvar_free();
		exit(EXIT_FAILURE);
	}

	a = (*head)->next;
	a->n /= (*head)->n;
	remove_top(head, ln);
}