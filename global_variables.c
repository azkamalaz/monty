#include "monty.h"

glob_t gvar;

/**
 * gvar_free - free gvar.
 * Return: nothing.
 */
void gvar_free(void)
{
	dlist_free(gvar.h);
	free(gvar.buf);
	fclose(gvar.filed);
}

/**
 * gvar_init - initialize the global variables.
 * @filed: file descriptor.
 * Return: nothing.
 */
void gvar_init(FILE *filed)
{
	gvar.s_or_q = 1;
	gvar.curr = 1;
	gvar.arg = NULL;
	gvar.h = NULL;
	gvar.filed = filed;
	gvar.buf = NULL;
}
