#include "monty.h"
/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *filed;
	size_t s = 256;
	ssize_t n = 0;
	char *l[2] = {NULL, NULL};

	filed = _check(argc, argv);
	gvar_init(filed);
	n = getline(&gvar.buf, &s, filed);
	while (n != -1)
	{
		l[0] = str_token(gvar.buf, " \t\n");
		if (l[0] && l[0][0] != '#')
		{
			f = opcode_select(l[0]); /*yet*/
			if (!f)
			{
				dprintf(2, "L%u: ", gvar.curr);
				dprintf(2, "unknown instruction %s\n", l[0]);
				gvar_free();
				exit(EXIT_FAILURE);
			}
			gvar.arg = str_token(NULL, " \t\n");
			f(&gvar.h, gvar.curr);
		}
		n = getline(&gvar.buf, &s, filed);
		gvar.curr++;
	}

	gvar_free();

	return (0);
}
