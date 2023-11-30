#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define LINESIZE 256
int main(int argc, char* argv[]) {
int fd[2];
pid_t pid;
if (pipe(fd) == -1) { perror("pipe"); exit(EXIT_FAILURE); }
if ((pid = fork()) == -1) { perror("fork"); exit(EXIT_FAILURE); }
if (pid > 0) { /* parent */
close(fd[0]);
int file=open(argv[1],O_RDONLY);
if (file <0){ perror("open"); exit(EXIT_FAILURE); }
char line[LINESIZE];
int nbytes=read(file,line,LINESIZE);
while (nbytes>0)
{
    write(fd[1],line, nbytes);
    nbytes=read(file, line,LINESIZE);
}
close(fd[1]);
if ( wait(NULL) == -1) { perror("wait"); exit(EXIT_FAILURE); }
exit(EXIT_SUCCESS);
} else { /* child */
char line[LINESIZE];
close(fd[1]);

int nbytes = read(fd[0], line, LINESIZE);
while (nbytes>0)
{
    write(STDOUT_FILENO, line, nbytes);
    nbytes=read(fd[0], line,LINESIZE);
}
close(fd[0]);
exit(EXIT_SUCCESS);
}
}