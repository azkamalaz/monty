#include "monty.h"
/**
 * print_str - prints the string of the stack
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void print_str(stack_t **head, unsigned int ln)
{
	stack_t *a;
	(void)ln;

	a = *head;

	while (a && a->n > 0 && a->n < 128)
	{
		printf("%c", a->n);
		a = a->next;
	}

	printf("\n");
}
