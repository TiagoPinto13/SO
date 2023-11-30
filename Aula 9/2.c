#include <sys/wait.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#define LINESIZE 1024
int main(int argc, char *argv[])
{
    int sockets[2], retv;

    retv = socketpair(AF_UNIX, SOCK_STREAM, 0, sockets);

    if (retv == -1)
    {
        perror("socketpair");
        exit(EXIT_FAILURE);
    }

    retv = fork();

    if (retv == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (retv > 0)
    { /* parent */
        close(sockets[1]);

        char string1[LINESIZE];

        int file = open(argv[1], O_RDONLY);
        if (file ==-1)
        {
            perror("open");
            exit(EXIT_FAILURE);
        }

        int nbytes = read(file, string1, LINESIZE);
        while (nbytes > 0)
        {
            write(sockets[0], string1, nbytes);
            read(sockets[0], string1, nbytes);
            write(STDOUT_FILENO,string1,nbytes);
            nbytes = read(file, string1, LINESIZE);
        }
        close(file);
        close(sockets[0]);

        retv = wait(NULL);
        if (retv == -1)
        {
            perror("wait");
            exit(EXIT_FAILURE);
        }
    }
    else

    { /* child */
        close(sockets[0]);
        char string2[LINESIZE];
        

        int nbytes = read(sockets[1], string2, LINESIZE);
        while (nbytes > 0)
        {
            for (int i = 0; i < nbytes; i++)
            {
                string2[i] = toupper(string2[i]);
            }
            write(sockets[1], string2, nbytes);
            nbytes = read(sockets[1], string2, LINESIZE);
        }
        close(sockets[1]);
        exit(EXIT_SUCCESS);
    }
}