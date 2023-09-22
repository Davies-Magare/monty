#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: The stack
 * @line_number: The file line number
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		if ((*stack) != NULL)
			(*stack)->prev = NULL;
		free(temp);
	}
}


