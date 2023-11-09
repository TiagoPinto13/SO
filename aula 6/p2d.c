#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
for (int i = 0; i < 4; i++) fork();
  printf("Child : %d\n",getpid());
  exit(EXIT_SUCCESS);
}