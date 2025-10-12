#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <stdlib.h>   

int main()
{
    pid_t pid;
    int rv;
    switch(pid = fork())
    {
        case -1:
            perror("Fork");
            exit(1);
        case 0:
            printf("\nChild: This is the child process\n");
            fflush(stdout);
            printf("\nChild: My pid is %d\n", getpid());
            printf("\nChild: My parent's pid is %d\n", getppid());
            printf("\nChild:Enter my exit status (make it small):\n");
            printf("\nChild:I'm outta here..!\n");
            scanf("%d", &rv);
            exit(rv);
        default:
        printf("\nParent: This is the parent process\n");
        printf("\nParent: My pid is %d\n", getpid());
        fflush(stdout);
        wait(&rv);
        fflush(stdout);
        printf("\nParent: My child's pid is %d\n", pid);
        printf("\nParent: I'm now wating for my child to exit\n");
        fflush(stdout);
        printf("\nParent: My child's exit status is %d\n", WEXITSTATUS(rv));
        printf("\nParent: I'm outta here..!\n");
        exit(0);
    }
}