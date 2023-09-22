#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: The stack
 * @line_number: The line_number
 *
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *new;

	n = flag.n;
	if (flag.err_flag)
		fprintf(stderr, "L %i: usage: push integer\n", line_number);
	else
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(new);
			exit(EXIT_FAILURE);
		}

		new->n = n;
		new->prev = NULL;
		new->next = NULL;
		if (*stack == NULL)
			*stack = new;
		else
		{
			new->next = *stack;
			(*stack)->prev = new;
			*stack = new;
		}
	}
}
/**
 * pall - prints all the elements on the stack
 * @stack: The stack
 * @line_number: The line number
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints the value on top of the stack
 * @stack: The stack
 * @line_number: The instruction number in the file
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		flag.err_flag = 1;
		fprintf(stderr, "L %i: can't pint, stack empty\n", line_number);
	}
	else
		printf("%i\n", (*stack)->n);
}
