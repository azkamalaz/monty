#include "monty.h"
/**
 * add_top_stack - adds the top two elements of the stack.
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void add_top_stack(stack_t **head, unsigned int ln)
{
	int i = 0;
	stack_t *a = NULL;

	a = *head;

	for (; a != NULL; a = a->next, i++);

	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", ln);
		gvar_free();
		exit(EXIT_FAILURE);
	}

	a = (*head)->next;
	a->n += (*head)->n;
	remove_top(head, ln);
}