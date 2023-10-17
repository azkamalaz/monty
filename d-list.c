#include "monty.h"

/**
 *add_node_end - add node at the end.
 *@h: head of linked list.
 *@data: data to store.
 *Return: d-list.
 */
stack_t *add_node_end(stack_t **h, const int data) 
{
	stack_t *tmp, *a;

	if (h == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		gvar_free();
		exit(EXIT_FAILURE);
	}
	tmp->n = data;
	/*Careful with the first time*/
	if (*h == NULL)
	{
		tmp->next = *h;
		tmp->prev = NULL;
		*h = tmp;
		return (*h);
	}
	a = *h;
	while (a->next)
		a = a->next;
	tmp->next = a->next;
	tmp->prev = a;
	a->next = tmp;
	return (a->next);
}

/**
 *add_node - add a node at the begining of the doubly link list.
 *@h: head of linked list.
 *@data: data to store.
 *Return: d-list.
 */
stack_t *add_node(stack_t **h, const int data) 
{
	stack_t *tmp;

	if (h == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		gvar_free();
		exit(EXIT_FAILURE);
	}
	tmp->n = data;
	/*Careful with the first time*/
	if (*h == NULL)
	{
		tmp->next = *h;
		tmp->prev = NULL;
		*h = tmp;
		return (*h);
	}
	(*h)->prev = tmp;
	tmp->next = (*h);
	tmp->prev = NULL;
	*h = tmp;
	return (*h);
}

/** 
 * dlist_free - free doubly linked list.
 * @h: head of the list.
 * Return: nothing.
 */
void dlist_free(stack_t *h) 
{
	stack_t *tmp;

	while ((tmp = h) != NULL)
	{
		h = h->next;
		free(tmp);
	}
}
