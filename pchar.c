#include "monty.h"
/**
 * print_char - print the char value of the first element.
 * @head: head of the linked list.
 * @ln: line number.
 * Return: nothing.
 */
void print_char(stack_t **head, unsigned int ln)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", ln);
		gvar_free();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", ln);
		gvar_free();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}