#include "shell.h"

#define MAX_INPUT 1024
#define MAX_ARGS 64

int shell(void)
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];
    char *token;
    int i;
    pid_t pid;

    while (1) {
        printf("$ ");

        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        token = strtok(input, " ");
        i = 0;

        while (token != NULL && i < MAX_ARGS - 1) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
    }

    printf("\n");

    return 0;
}

