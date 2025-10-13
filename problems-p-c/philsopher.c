#include <stdio.h>
#include <stdlib.h>

void one(void);
void two(void);

int tph, philname[20], status[20], howhung, hu[20], cho;

int main()
{
    int i;
    printf("\n\nDining Philosophers Problem\n");
    printf("\nEnter the total number of philosophers: ");
    scanf("%d", &tph);

    for (i = 0; i < tph; i++)
    {
        philname[i] = i + 1;
        status[i] = 0;
    }

    printf("How many are hungry: ");
    scanf("%d", &howhung);

    if (howhung == tph)
    {
        printf("\nDeadlock occurs as all are hungry\n");
        printf("\nExiting...\n");
        exit(0);
    }
    else
    {
        for (i = 0; i < howhung; i++)
        {
            printf("Enter philosopher %d position: ", i + 1);
            scanf("%d", &hu[i]);
            status[hu[i]] = 2;
        }

        do
        {
            printf("\n1. One philosopher can eat at a time\n2. Two philosophers can eat at a time\n3. Exit\nEnter your choice: ");
            scanf("%d", &cho);

            switch (cho)
            {
            case 1:
                one();
                break;

            case 2:
                two();
                break;

            case 3:
                printf("\nExiting...");
                exit(0);

            default:
                printf("\nInvalid choice");
            }
        } while (1);
    }
}

void one(void)
{
    int pos = 0, x, i;
    printf("\nOne philosopher can eat at a time\n");

    for (i = 0; i < howhung; i++, pos++)
    {
        printf("\n\np%d is granted to eat", philname[hu[pos]]);
        for (x = 0; x < howhung; x++)
        {
            if (x != pos)
                printf("\np%d is waiting", philname[hu[x]]);
        }
    }
}

void two(void)
{
    int i, j, s = 0, t, r, x;
    printf("\nAllow two philosophers to eat at the same time\n");

    for (i = 0; i < howhung; i++)
    {
        for (j = i + 1; j < howhung; j++)
        {
            printf("\n\nCombination %d", (s + 1));
            s++;
            t = hu[i];
            r = hu[j];

            printf("\n\np%d and p%d are granted to eat", philname[t], philname[r]);

            for (x = 0; x < howhung; x++)
            {
                if (hu[x] != t && hu[x] != r)
                {
                    printf("\np%d is waiting", philname[hu[x]]);
                }
            }
        }
    }
}
