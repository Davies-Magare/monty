#include "monty.h"

/**
 * search_execute - searches for the opcode function and calls it
 * @input: The opcode function specified by the user
 * @stack: The stack
 * @line_number: The line number in the file
 *
 * Return: 1 in case of error, Otherwise return 0
 */
void search_execute(char *input, stack_t **stack, int line_number)
{
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i;
	int ret, zero_flag;
	char *numeral, *operation;
	
	flag.err_flag = 0;
	for (i = 0, zero_flag = 0; input[i] != '\0' && !zero_flag; i++)
		if (input[i] == '0')
			zero_flag = 1;
	operation = strtok(input, " \n");
	if (operation == NULL)
	{
		flag.err_flag = -1;
		return;
	}
	numeral = strtok(NULL, " \n");
	flag.n = (numeral != NULL) ? atoi(numeral) : 0;
	ret = strcmp("push", operation);
	flag.err_flag = (ret == 0 && zero_flag== 0 && flag.n == 0) ? 1 : 0;
	i = 0;
	while (functions[i].opcode != NULL)
	{
		if ((strcmp(functions[i].opcode, operation) == 0))
			break;
		i++;
	}
	if (functions[i].opcode == NULL)
	{
		fprintf(stderr, "L<%i>: unknown instruction<%s>\n", line_number, operation);
		flag.err_flag = 1;
	}
	functions[i].f(stack, line_number);
}
/**
 * free_stack - frees the stack
 * @stack: The stack
 *
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

