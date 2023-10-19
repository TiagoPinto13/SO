#include <stdio.h>
int main (int ac, char* av[]) {
  printf("# arguments = %d\n", ac - 1);
  printf("the command arguments are: %s\n", av[0]);
  for (int i = 1; i < ac ; i++)
    printf("argv[%d]=%s\n", i, av[i]);
  return 0;
}