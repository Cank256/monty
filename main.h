#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct custom_stack_s
{
    int n;
    struct custom_stack_s *prev;
    struct custom_stack_s *next;
} custom_stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(custom_stack_t **stack, unsigned int line_number);
} instruction_t;

void push(custom_stack_t **stack, unsigned int line_number);
void pall(custom_stack_t **stack, unsigned int line_number);

#endif
