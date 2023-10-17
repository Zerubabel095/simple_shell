#include "shell.h"

#define MAX_INPUT 1024
#define MAX_ARGS 64

int path(void)
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];
    char *token;
    char *path;
    char *dir;
    char command[MAX_INPUT];
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

        path = getenv("PATH");
        dir = strtok(path, ":");

        while (dir != NULL) {
            snprintf(command, sizeof(command), "%s/%s", dir, args[0]);

            if (access(command, X_OK) == 0) {
                pid = fork();

                if (pid == 0) {
                    execv(command, args);
                    perror("execv");
                    exit(EXIT_FAILURE);
                } else if (pid < 0) {
                    perror("fork");
                    exit(EXIT_FAILURE);
                } else {
                    wait(NULL);
                }

                break;
            }

            dir = strtok(NULL, ":");
        }
    }

    printf("\n");

    return 0;
}

