#include "monty.h"
/**
 * rotates_left - rotates the first element.
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void rotates_left(stack_t **head, unsigned int ln)
{
	stack_t *a1 = NULL;
	stack_t *a2 = NULL;
	(void)ln;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	a1 = (*head)->next;
	a2 = *head;

	for (; a2->next != NULL; a2 = a2->next);

	a1->prev = NULL;
	a2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = a2;
	*head = a1;
}