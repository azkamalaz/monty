#include "monty.h"
/**
 * remove_top - removes the top element of the stack.
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void remove_top(stack_t **head, unsigned int ln)
{
	stack_t *a;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", ln);
		gvar_free();
		exit(EXIT_FAILURE);
	}
	a = *head;
	*head = (*head)->next;
	free(a);
}
