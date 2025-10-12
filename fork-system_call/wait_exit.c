#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int i,pid;
    pid = fork();

    if(pid == -1)
    {
        perror("Fork failed");
        exit(0);
    }
    else if(pid == 0)
    {
        printf("\nchild process starts\n");
        // Child process
        for(i=0; i<5; i++)
        {
            printf("Child Process: %d is called\n", i);
            sleep(1);
        }
        printf("\nchild process ends\n");
    }
    else
    {
       wait(0); // Parent process waits for child to complete
       printf("\nparent process ends\n");
    }
    exit(0);
}