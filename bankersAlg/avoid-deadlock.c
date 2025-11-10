#include <stdio.h>

struct process
{
    int allocation[3];
    int max[3];
    int need[3];
    int finish;
} p[10];

int main()
{
    int n, i, j, avail[3], work[3], count = 0, sequence[10], k = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the %dth process allocation resources: ", i);
        scanf("%d%d%d", &p[i].allocation[0], &p[i].allocation[1], &p[i].allocation[2]);

        printf("Enter the %dth process maximum resources: ", i);
        scanf("%d%d%d", &p[i].max[0], &p[i].max[1], &p[i].max[2]);

        p[i].finish = 0;

        for (j = 0; j < 3; j++)
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
    }

    printf("Enter the Available vector: ");
    scanf("%d%d%d", &avail[0], &avail[1], &avail[2]);

    for (i = 0; i < 3; i++)
        work[i] = avail[i];

    int finished_count = 0;

    while (finished_count < n)
    {
        int allocated = 0;

        for (i = 0; i < n; i++)
        {
            if (p[i].finish == 0 &&
                p[i].need[0] <= work[0] &&
                p[i].need[1] <= work[1] &&
                p[i].need[2] <= work[2])
            {
                for (j = 0; j < 3; j++)
                    work[j] += p[i].allocation[j];

                p[i].finish = 1;
                sequence[k++] = i;
                finished_count++;
                allocated = 1;
            }
        }

        if (!allocated) // No process was allocated this round → deadlock
            break;
    }

    if (finished_count == n)
    {
        printf("\nThe safe sequence is: ");
        for (i = 0; i < n; i++)
            printf("%d ", sequence[i]);
    }
    else
        printf("\nSystem is NOT in safe state\n");

    return 0;
}
