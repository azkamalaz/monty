#include "monty.h"
/**
 * reverse - reverse the stack.
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void reverse(stack_t **head, unsigned int ln)
{
	stack_t *a = NULL;
	(void)ln;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	a = *head;

	for (; a->next != NULL; a = a->next)
	;

	a->prev->next = NULL;
	a->next = *head;
	a->prev = NULL;
	(*head)->prev = a;
	*head = a;
}
