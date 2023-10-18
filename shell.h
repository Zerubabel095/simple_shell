#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void);
int shell(void);
int path(void);
void exit_shell(void);
int execute_line(char* line);
char* get_line(void);
int exit_main();
char* get_line();
void execute_command(char **args);

#endif

