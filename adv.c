#include "monty.h"

/**
 * mul_func - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: The stack
 * @line_number: The line number
 *
 * Return: Nothing
 */
void mul_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
	}
	else
	{
		(*stack)->next->n *= (*stack)->n;
		pop(stack, line_number);
	}
}

/**
 * mod_func - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: The stack
 * @line_number: The file line number
 *
 * Return: Nothing
 */
void mod_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
	}
	else if ((*stack)->n == 0)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: division by zero\n", line_number);
	}
	else
	{
		(*stack)->next->n %= (*stack)->n;
		pop(stack, line_number);
	}
}
