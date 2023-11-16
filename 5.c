#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#define MAXARGS 32
#define MAX_HISTORY_SIZE 32
char* history[MAX_HISTORY_SIZE];
int history_count = 0;

int main(int argc, char* argv[]) {
  for( ; ; ) {
    /* give prompt, read command and null terminate it */
    fprintf(stdout, "$ ");
    char buf[1024];
    char* command = fgets(buf, sizeof(buf), stdin);
    if(command == NULL)
      break;
    
    command[strlen(buf) - 1] = '\0';
    if (strcmp(command,"exit")==0)
      break;
    /* call fork and check return value */
    pid_t pid = fork();
    if(pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    if(pid == 0) {
      /* child */
      char* args[MAXARGS];
      int i=0;
      char*p=strtok(command," ");
      while(p!=NULL){
        args[i]=strdup(p);
        i++;
        p=strtok(NULL," ");
        }
      args[i]=NULL;
      if(strcmp(args[0],"myhistory")==0){
        int n= atoi(args[1]);
        for(int i=0;i<n;i++){
          printf("%s \n",history[i]);
          }
        }
      if (history_count < MAX_HISTORY_SIZE) {
            history[history_count] = strdup(command);
            history_count++;
        } 
    else {
        free(history[0]);
        for (int i = 0; i < MAX_HISTORY_SIZE - 1; i++) {
            history[i] = history[i + 1];
        }
        history[MAX_HISTORY_SIZE - 1] = strdup(command);
    }
    
      int retv =execvp(args[0],args);
      
      if(retv == -1) {
        perror("execlp");
        exit(EXIT_FAILURE);
      }
    }
    /* shell waits for command to finish before giving prompt again */
    int retv = waitpid(pid, NULL, 0);
    if (retv == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
  }
  exit(EXIT_SUCCESS);
}