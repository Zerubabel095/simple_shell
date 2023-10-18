#include <stdio.h>
#include <stdlib.h>

char **env;
int strcmp(const char *s1, const char *s2);
extern char **environ;

void print_env(void)
{
    env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}
int execute_lines()
{
    char *args[100];
    args[0] = "";

    if (args[0] == NULL){
      return 1;
    }	    

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "env") == 0) {
        print_env();
        return 1;
    }

    return 0;
}

