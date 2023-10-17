#include "monty.h"
/**
 * swap_to_top - swaps the top two elements of the stack.
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void swap_to_top(stack_t **head, unsigned int ln)
{
	int i = 0;
	stack_t *a = NULL;

	a = *head;

	for (; a != NULL; a = a->next, i++);

	if (i < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", ln);
		gvar_free();
		exit(EXIT_FAILURE);
	}

	a = *head;
	*head = (*head)->next;
	a->next = (*head)->next;
	a->prev = *head;
	(*head)->next = a;
	(*head)->prev = NULL;
}
