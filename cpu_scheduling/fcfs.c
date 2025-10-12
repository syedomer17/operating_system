#include <stdio.h>

int main()
{
    char pn[10][10];
    int arr[10], bur[10], stat[10], finish[10], tat[10], wt[10], i, n;
    float totwt = 0, tottat = 0; // ✅ FIX 1: Added initialization for totals

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter process name, arrival time and burst time: ");
        scanf("%s %d %d", pn[i], &arr[i], &bur[i]); // ✅ FIX 2: Removed '&' before pn[i]
        // '&pn[i]' passes the address of the array of chars, but scanf("%s") expects a char pointer (pn[i])
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            stat[i] = arr[i];
            wt[i] = stat[i] - arr[i];
            finish[i] = stat[i] + bur[i];
        }
        else
        {
            stat[i] = finish[i - 1];
            wt[i] = stat[i] - arr[i];
            if (wt[i] < 0) // ✅ FIX 3: Handle negative waiting time (CPU idle time)
                wt[i] = 0;
            finish[i] = stat[i] + bur[i];
        }

        tat[i] = finish[i] - arr[i]; // ✅ FIX 4: Added turnaround time calculation
    }

   printf("\n------------------------------------------------------------------------------------------");
    printf("\n%-10s %-15s %-12s %-12s %-14s %-16s %-12s",
           "Process", "Arrival Time", "Burst Time", "Start Time", "Waiting Time", "Turnaround Time", "Finish Time");
    printf("\n------------------------------------------------------------------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\n%-12s\t%6d\t\t%6d\t\t%6d\t\t%6d\t\t%6d\t\t%6d", 
               pn[i], arr[i], bur[i], stat[i], wt[i], tat[i], finish[i]);
        totwt += wt[i];   // ✅ FIX 5: Declared and initialized totwt above
        tottat += tat[i]; // ✅ FIX 6: Declared and initialized tottat above
    }

    printf("\n\nAverage waiting time: %.2f", totwt / n);
    printf("\nAverage turnaround time: %.2f\n", tottat / n);

    return 0;
}
