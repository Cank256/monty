#include "main.h"

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {NULL, NULL}
};

int main(int argc, char *argv[])
{
    char buffer[1024];
    unsigned int line_number = 0;
    custom_stack_t *stack = NULL;
    int i = 0;
    char *opcode = strtok(buffer, " \t\n");
    FILE *file = fopen(argv[1], "r");

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), file))
    {
        line_number++;

        if (opcode == NULL)
            continue;

        while (instructions[i].opcode != NULL)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number);
                break;
            }
            i++;
        }

        if (instructions[i].opcode == NULL)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            return EXIT_FAILURE;
        }

        i = 0; 
    }

    fclose(file);
    return EXIT_SUCCESS;
}
