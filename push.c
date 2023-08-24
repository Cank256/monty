#include "main.h"

void push(custom_stack_t **stack, unsigned int line_number)
{
    char *value_str = strtok(NULL, " ");
    int value = atoi(value_str);
    custom_stack_t *new_node = malloc(sizeof(custom_stack_t));
    if (value_str == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
