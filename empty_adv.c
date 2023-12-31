#include "monty.h"

/**
 * nop - does nothing
 * @stack: The stack
 * @line_number: The file line number
 *
 * Return: Nothing
 */
void nop(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
}
/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack
 * @stack: The stack
 * @line_number: The file line number
 *
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
	}
	else
	{
		(*stack)->next->n -= (*stack)->n;
		pop(stack, line_number);
	}
}
/**
 * div - divides the second top element of the stack by
 * the element on top of the stack
 * @stack: The stack
 * @line_number: The file line number
 *
 * Return: Nothing
 */
void div_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
	}
	else if ((*stack)->n == 0)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L%i: division by zero\n", line_number);
	}
	else
	{
		(*stack)->next->n /= (*stack)->n;
		pop(stack, line_number);
	}
}
