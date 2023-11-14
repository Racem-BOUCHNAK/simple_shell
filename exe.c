#include "hsh.h"

/**
 * command_exists - Checks if a command exists in the PATH
 * @cmd: The command to check
 *
 * Return: 1 if command exists, 0 otherwise
 */

int command_exists(char *cmd) {
	char *path, *temp, *token, *full_path;
	struct stat st;
	size_t full_path_size;
	int cmd_exists = 0;

	if (strchr(cmd, '/')) {
		return stat(cmd, &st) == 0;
		}

	path = getenv("PATH");
	if (!path) {
		return 0;
		}

	temp = malloc(strlen(path) + 1);
	if (temp == NULL) {
		fprintf(stderr, "lsh: memory allocation error\n");
		return 0;
		}
	strcpy(temp, path);

	token = strtok(temp, ":");
	while (token != NULL) {
		full_path_size = strlen(token) + strlen(cmd) + 2;
		full_path = malloc(full_path_size);
		if (full_path == NULL) {
			fprintf(stderr, "lsh: memory allocation error\n");
			free(temp);
			return 0;
			}

		snprintf(full_path, full_path_size, "%s/%s", token, cmd);
		if (stat(full_path, &st) == 0) {
			cmd_exists = 1;
			free(full_path);
			break;
			}

		free(full_path);
		token = strtok(NULL, ":");
		}

	free(temp);
	return cmd_exists;
}


/**
 * execute - Executes a command
 * @args: array of argument strings
 * 
 * Description: Executes the command provided in args. If the command is a built-in,
 * it executes it directly..
 * 
 * Return: 1 on completion of command execution.
 */

int execute(char **args) {
	pid_t pid;
	int status;

	if (args[0] == NULL) {
        return 1;
		}

	if (execute_builtin(args)) {
		return 1;
		}

	if (!command_exists(args[0])) {
		fprintf(stderr, "Command not found: %s\n", args[0]);
		return 1;
		}

	pid = fork();
	if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			perror("lsh");
			}
		exit(EXIT_FAILURE);
		}
	else if (pid < 0) {
		perror("lsh");
		}
	else {
		do {
			waitpid(pid, &status, WUNTRACED);
			}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}

	return 1;
}


/**
 * execute_builtin - Executes built-in shell commands
 * @args: Arguments
 *
 * Return: 1 if a built-in command was executed, 0 otherwise
 */

int execute_builtin(char **args) {
    int i;

    if (args[0] == NULL) {
        return 0;
    }

    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	} else {
            if (chdir(args[1]) != 0) {
                perror("lsh");
	    }
	}
        return 1;
    } else if (strcmp(args[0], "exit") == 0) {
        exit(EXIT_SUCCESS);
    } else if (strcmp(args[0], "env") == 0) {
        i = 0;
        while (environ[i] != NULL) {
            printf("%s\n", environ[i]);
            i++;
	}
        return 1;
    }

    return 0;
}
