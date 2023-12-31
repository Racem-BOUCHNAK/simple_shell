#include "hsh.h"

/**
 * _read - Read Command
 * @filename:Filename
 * @argv:Program Name
 * Return: -1 or  0
 */

void _read(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		treat(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * treat - PARSE Check Command
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * Return : Excute A line void
 */

void treat(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			exit_bul(cmd, line, fp);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free(cmd);
		}
		else
		{
			st = check_cmd(cmd, line, counter, argv);
			free(cmd);
		}
}

/**
 * exit_bul - Exit Shell
 * @line: Line From A File
 * @cmd: Parsed Command
 * @fd:File Descriptor
 * Return : Exit
 */

void exit_bul(char **cmd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);
}
