#include <stdio.h>

void main()
{
    int buffer[10], bufsize, in, out, produce, consume, choice = 0;
    in = 0;
    out = 0;

    printf("Enter the buffer size (max 10): ");
    scanf("%d", &bufsize);

    while (choice != 3)
    {
        printf("\n1. Producer\n2. Consumer\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if ((in + 1) % bufsize == out)
            {
                printf("\nBuffer is full");
            }
            else
            {
                printf("\nEnter the value: ");
                scanf("%d", &produce);
                buffer[in] = produce;
                in = (in + 1) % bufsize;
                printf("Produced item: %d", produce);
            }
            break;

        case 2:
            if (in == out)
            {
                printf("\nBuffer is empty");
            }
            else
            {
                consume = buffer[out];
                printf("\nThe consumed value is %d", consume);
                out = (out + 1) % bufsize;
            }
            break;

        case 3:
            printf("\nExiting...");
            break;

        default:
            printf("\nInvalid choice");
            break;
        }
    }
}
