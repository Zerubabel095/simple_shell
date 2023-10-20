#include "shell.h"

/**
 * _strlen - calculates the length of a string
 * @s: the string to calculate the length of
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}
/*a function that compares two strings*/
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}
/* This function works in a similar way to the _strcmp() function */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    while (*s1 && *s2 && *s1 == *s2 && n > 0) {
        s1++;
        s2++;
        n--;
    }

    if (n == 0) {
        return 0;
    } else {
        return *s1 - *s2;
    }
}
/* character locter  in the  string */
char *_strchr(char *s, char c) {
  while (*s != '\0') {
    if (*s == c) {
      return s;
    }
    s++;
  }

  return NULL;
}
/*The function returns a pointer to a duplicate of the string s */
char *_strdup(const char *s) 
{
	size_t len = strlen(s) + 1;
	char *dup = malloc(len);
	if (dup == NULL) 
	{
		return NULL;
	}

	memcpy(dup, s, len);
	return dup;
}
