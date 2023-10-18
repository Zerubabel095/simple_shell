#include <stdio.h>

int buff_main(void) {
  size_t bufsize;
  char *line;

  getline(&line, &bufsize, stdin);

  printf("You entered the line: %s\n", line);

  free(line);

  return 0;
}

 

