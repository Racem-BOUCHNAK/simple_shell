#include "hsh.h"

/**
 * read_line - Reads a line from standard input
 *
 * Description: Reads a line from the standard
 *
 * Return: Pointer to the read line
 */

char *read_line()
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t line_size;

	line_size = custom_getline(&line, &bufsize, STDIN_FILENO);
	if (line_size <= 0) {
        free(line);
        return NULL;
	}

    return line;
}

char **split_line(char *line)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
	fprintf(stderr, "lsh: allocation error\n");
	exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIM);
	while (token != NULL)
	{
	tokens[position++] = token;
	if (position >= bufsize)
	{
	bufsize += 64;
	tokens = realloc(tokens, bufsize * sizeof(char *));
	if (!tokens)
	{
	fprintf(stderr, "lsh: allocation error\n");
	exit(EXIT_FAILURE);
	}
	}
	token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
