#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
  int pid;
  for(int i=1; i<4; i++){
    pid=fork();
    if(pid==-1){
      perror("fork:");
      exit(EXIT_FAILURE);
      }
    }
    printf("Child : %d\n",getpid());
exit(EXIT_SUCCESS);
}