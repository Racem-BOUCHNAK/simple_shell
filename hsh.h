#ifndef hsh_h
#define hsh_h

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_LEN 1024
#define DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024


int main();
void loop();
char *read_line();
char **split_line(char *line);
int execute(char **args);
int execute_builtin(char **args);
int command_exists(char *cmd);
ssize_t custom_getline(char **lineptr, size_t *n, int fd);

extern char **environ;

#endif
