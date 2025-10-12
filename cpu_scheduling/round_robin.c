#include <stdio.h>

struct process
{
    int burst;
    int wait;
    int comp;
    int f;
} p[20];

int main()
{
    int n, i, j, totalWait = 0, totalTurn = 0, quantum, flag = 1, time = 0;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the quantum time (in ms): ");
    scanf("%d", &quantum);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the burst time (in ms) for process #%2d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].comp = 0; // completed time counter
        p[i].f = 1;    // flag means process is not yet finished
        p[i].wait = 0;
    }

    printf("\nOrder of execution:\n");
    printf("------------------------------------------------------------\n");
    printf("Process\tStart\tEnd\tRemaining\n");
    printf("------------------------------------------------------------\n");

    while (flag == 1)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (p[i].f == 1)
            {
                flag = 1;
                int start = time;
                int exec;

                if ((p[i].burst - p[i].comp) > quantum)
                {
                    exec = quantum;
                    p[i].comp += quantum;
                    time += quantum;
                }
                else
                {
                    exec = p[i].burst - p[i].comp;
                    time += exec;
                    p[i].comp = p[i].burst;
                    p[i].wait = time - p[i].burst;
                    p[i].f = 0;
                }

                printf("P%-7d%-7d%-7d%-7d\n", i + 1, start, time, p[i].burst - p[i].comp);
            }
        }
    }

    printf("------------------------------------------------------------\n");
    printf("\nProcess\tWaiting\tTurnaround\n");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("P%-7d%-7d%-7d\n", i + 1, p[i].wait, p[i].wait + p[i].burst);
        totalWait += p[i].wait;
        totalTurn += p[i].wait + p[i].burst;
    }

    printf("------------------------------------------------------------\n");
    printf("\nAverage waiting time: %.2f ms", (float)totalWait / n);
    printf("\nAverage turnaround time: %.2f ms\n", (float)totalTurn / n);

    return 0;
}
