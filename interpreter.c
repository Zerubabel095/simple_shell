#include "shell.h"

#define MAX_INPUT 1024
char input[MAX_INPUT];
char *args[2];
pid_t pid;

int main(void)
{

    while (1) {
        printf("$ ");

        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        args[0] = input;
        args[1] = NULL;

        pid = fork();

        if (pid == 0) {
            execve(args[0], args, NULL);
            perror("execve");
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
