#include "hsh.h"

void loop(void);

/**
 * main - Entry point of the program
 * Return: EXIT_SUCCESS on successful execution
 */
int main()
{
	loop();
	return EXIT_SUCCESS;
}

/**
 * loop - Repeatedly prompts the user
 */
void loop() {
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = read_line();
		args = split_line(line);
		status = execute(args);
		free(line);
		free(args);
	}
	while (status);
}
