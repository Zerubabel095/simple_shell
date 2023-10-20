#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int shell_main();
char *path_finder(void);
void exit_shell(char **command_args, char *input);
void buffer_free(char **buf);
void _signal(int s);
void print_prompt(void);
char **tokenize_input(char *input);
int builtin_check(char **cmd, char *buf);
char *get_path_command(char **path, char *command_args);
char *add_path(char *path, char *command_args);
int builtins(char **command_args, char *input);
void execute_command(char* cp, char** cmd);
void environment(void);

/*strings*/
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *s);
char *_strchr(char *s, char c);

/* environment */
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern char **environ;

struct info {
  int exit_code;
  int line_number;
} info;

struct flags
{
	bool interactive;
} flags;
struct builtin
{
	char *env;
	char *exit;
} builtin;


#endif

