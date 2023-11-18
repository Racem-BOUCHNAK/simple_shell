#include "hsh.h"

/**
 * prompt - Display Prompt
 */
void prompt(void)
{
	PRINTER("$ ");
}
/**
 * error - Display Error
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
