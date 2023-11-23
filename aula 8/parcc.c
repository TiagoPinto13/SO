#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]){
    for (int i=1;i<argc;i++){
        pid_t pid=fork();
        if(pid==0){
            printf("%d: compiling %s\n",getpid(),argv[i]);
            char* args[5];
            args[0]="gcc";
            args[1]="-Wall";
            args[2]="-c";
            args[3]=strdup(argv[i]);
            args[4]=NULL;
            execvp(args[0],args);
        }
    }
    for (int i=1; i<argc;i++)
        wait(NULL);
    exit(EXIT_SUCCESS);
}