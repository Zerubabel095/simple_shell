#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_LINE 80

char* line;
size_t bufsize;
pid_t pid;
int status;
char* args[MAX_LINE/2 + 1];
char *line;
int i;

char* get_line() {
    line = NULL;
    bufsize = 0;
    getline(&line, &bufsize, stdin);
    return line;
}

void execute_command(char **args) {
    if ((pid = fork()) < 0) {
        printf("Error: Failed to fork process\n");
        return;
    } else if (pid == 0) {
      
        if (execvp(args[0], args) < 0) {
            printf("Error: Command not found\n");
        }
        exit(1);
    } else {
 	
        wait(&status);

        if (args[1] != NULL) {
            if (strcmp(args[1], "&&") == 0 && WEXITSTATUS(status) == 0) {
                execute_command(args + 2);
            } else if (strcmp(args[1], "||") == 0 && WEXITSTATUS(status) != 0) {
                execute_command(args + 2);
            }
        }
    }
}

int execute_line(char* line) {
    i = 0;

    args[i] = strtok(line, " \n");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " \n");
    }
    args[i] = NULL;

    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    execute_command(args);

    return 1;
}

int exit_main() {
    do {
        printf("$ ");
        line = get_line();
        status = execute_line(line);
        free(line);
    } while (status);

    return 0;
}
