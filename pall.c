#include "monty.h"
/**
 * print_all - prints all values on the stack.
 * @head: head of the linked list.
 * @ln: line numbers.
 * Return: nothing.
 */
void print_all(stack_t **head, unsigned int ln)
{
	stack_t *a;
	(void)ln;

	a = *head;

	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
}
