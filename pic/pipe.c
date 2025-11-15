#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define msgsize 29

int main() 
{
    int ser[2], cli[2], pid;
    char inbuff[msgsize];
    char *msg = "Thank you";

    system("clear");
    pipe(ser);
    pipe(cli);

    printf("Server read id=%d, write id=%d\n", ser[0], ser[1]);
    fflush(stdout);

    printf("Client read id=%d, write id=%d\n", cli[0], cli[1]);
    fflush(stdout);

    pid = fork();

    if(pid == 0){
        // child process - client
        printf("I am in child process!\n");
        printf("Client read id=%d, write id=%d\n", cli[0], cli[1]);
        fflush(stdout);

        close(cli[0]);
        close(ser[1]);

        write(cli[1], msg, msgsize);
        printf("Message written to pipe...!\n");
        fflush(stdout);

        sleep(2);

        read(ser[0], inbuff, msgsize);
        printf("Echo message received from server\n");
        printf("%s\n", inbuff);
        fflush(stdout);

    } else {
        // parent process - server
        printf("Parent process!\n");
        fflush(stdout);

        close(cli[1]);
        close(ser[0]);

        read(cli[0], inbuff, msgsize);
        write(ser[1], inbuff, msgsize);

        printf("Parent ended!\n");
        fflush(stdout);
    }

    return 0;
}
