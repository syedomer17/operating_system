#include <stdio.h>
#include <stdlib.h>      // Added for pthread_exit
#include <pthread.h>
#define NUM_THREADS 3

// Global variables
int je = 0, jo = 0;      
int t = 0, evensum = 0, sumn = 0, oddsum = 0;
int evenarr[50], oddarr[50];

// Thread function to find even numbers and their sum
void *Even(void *threadid)
{
    int i, n;
    je = 0;
    n = (int)(long)threadid;  //  proper cast from void* to int
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            evenarr[je] = i;
            evensum = evensum + i;   //  add the even number
            je++;
        }
    }
    pthread_exit(NULL);
}

// Thread function to find odd numbers and their sum
void *Odd(void *threadid)
{
    int i, n;
    jo = 0;
    n = (int)(long)threadid;  // proper cast
    for (i = 1; i <= n; i++)
    {
        if (i % 2 != 0)      
        {
            oddarr[jo] = i;
            oddsum = oddsum + i;   //  add the odd number
            jo++;
        }
    }
    pthread_exit(NULL);
}

// Thread function to find sum of first N natural numbers
void *SumN(void *threadid)
{
    int i, n;
    n = (int)(long)threadid;
    for (i = 1; i <= n; i++)
    {
        sumn = sumn + i;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int i;

    printf("Enter a number:\n");
    scanf("%d", &t);

    // Create threads
    pthread_create(&threads[0], NULL, Even, (void *)(long)t);  //  correct cast
    pthread_create(&threads[1], NULL, Odd, (void *)(long)t);
    pthread_create(&threads[2], NULL, SumN, (void *)(long)t);

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Display results
    printf("\nThe sum of first N natural numbers is: %d\n", sumn);
    printf("The sum of first N even natural numbers is: %d\n", evensum);
    printf("The sum of first N odd natural numbers is: %d\n", oddsum);

    printf("\nThe first N even natural numbers are:\n");
    for (i = 0; i < je; i++)
        printf("%d ", evenarr[i]);

    printf("\n\nThe first N odd natural numbers are:\n");
    for (i = 0; i < jo; i++)
        printf("%d ", oddarr[i]);

    printf("\n");
    pthread_exit(NULL);
}
