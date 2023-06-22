#include "monty.h"

/**
 * f_pall - a func that prints the stack
 * @head: pointer to the stack head
 * @counter: not used
 * Return: No return value implemented
 * Description: a func that prints all elements in the stack
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
	{
		return;
	}
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
