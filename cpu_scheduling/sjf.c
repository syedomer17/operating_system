#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, pno[10], bt[10], n, wt[10], temp = 0, j, tt[10];
    float sum = 0, at = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter burst time of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d: ", i );
        scanf("%d", &bt[i]);
        pno[i] = i;
    }

    // Sorting processes by burst time (SJF)
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++) 
        {
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pno[i];
                pno[i] = pno[j];
                pno[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
        sum = sum + wt[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tt[i] = bt[i] + wt[i];
        at += tt[i];
        printf("\np%d\t\t%d\t\t%d\t\t%d", pno[i], bt[i], wt[i], tt[i]);
    }

    printf("\n\nAverage waiting time: %.2f", sum / n);
    printf("\nAverage turnaround time: %.2f\n", at / n);

    return 0;
}
