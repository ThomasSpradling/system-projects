#include <stdio.h>

int my_strlen(char *s) {
  int i = 1;
  while (s[i] != '\0') i++;
  return i;
}

int main(int argc, char const *argv[])
{
  printf("%d\n", my_strlen("hello"));
  return 0;
}
