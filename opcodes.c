#include "monty.h"

/**
 * opcodes_select - get opcodes to perform.
 * @opcodes: opcode.
 * Return: pointer to function to executes the opcode.
 */
void (*opcodes_select(char *opcodes))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", add_to_stack},
		{"pall", print_all},
		{"pint", print_at_top},
		{"pop", remove_top},
		{"swap", swap_to_top},
		{"queue", set_to_queue},
		{"stack", set_to_stack},
		{"add", add_top_stack},
		{"nop", nothing},
		{"sub", subtracts},
		{"mul", multiplies},
		{"div", divides},
		{"mod", computes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotates_left},
		{"rotr", reverse},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opcodes) == 0)
			break;
	}

	return (instruct[i].f);
}