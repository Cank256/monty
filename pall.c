#include "main.h"

void pall(custom_stack_t **stack, unsigned int line_number)
{
    custom_stack_t *current = *stack;
    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}