#ifndef hSH_H
#define hSH_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>


char *_strtok(char *str, const char *tok);
unsigned int check_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);
void prompt(void);
void signal_to_handel(int sig);
char *_getline(void);
int path_cmd(char **line);
char *_getenv(char *name);
char **parse(char *cmd);
int handle_builtin(char **cmd, int er);
void _read(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void env(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat(char *line, int counter, FILE *fd, char **argv);
void exit_bul(char **cmd, char *line, FILE *fd);
void _hashtag(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int _env(char **cmd, int er);
int _cd(char **cmd, int er);
int _help(char **cmd, int er);
int _echo(char **cmd, int er);
void _exit_(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);
void print_number(unsigned int n);
void print_number_in(int n);
void error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);

extern char **environ;

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
