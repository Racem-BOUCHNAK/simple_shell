#include "hsh.h"

/**
 * main - Entry point of the program
 * Return: EXIT_SUCCESS on successful execution
 */

int main(void)
{
	loop();
	return (EXIT_SUCCESS);
}

/**
 * loop - Repeatedly prompts the user
 */

void loop(void)
{
   char *line;
    char **args;
    int status;

    do {
        printf("> ");
        fflush(stdout);

        line = read_line();
        if (line == NULL) {
            break;
	}

        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
}
