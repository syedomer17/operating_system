#include <stdio.h>

int main()
{
    int a[5], b[20], p = 0, q = 0, m = 0;
    int h, k, i, q1 = 1, j, u, n;
    char f = 'F';

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter %d page numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n; i++) {

        if (p == 0) {

            if (q >= 3) {
                q = 0;
            }

            a[q] = b[i];
            q++;

            if (q1 < 3) q1 = q;

            // PRINT SECTION
            printf("\n%d\t", b[i]);
            for (h = 0; h < q1; h++) {
                printf("%d", a[h]);
            }

            if (q <= 3) {
                printf("-->%c", f);
                m++;
            }
        }

        // RESET p for next round
        p = 0;

        // DECISION SECTION
        if (q1 == 3) {

            // Check if next page is present
            for (k = 0; k < q1; k++) {
                if (b[i + 1] == a[k]) {
                    p = 1;
                }
            }

            // Find victim frame
            for (j = 0; j < q1; j++) {
                u = 0;
                int temp = i;

                while (temp >= (i - 1) && temp >= 0) {
                    if (b[temp] == a[j]) {
                        u++;
                    }
                    temp--;
                }

                if (u == 0) {
                    q = j;   // replace this frame
                }
            }

        } else {

            for (k = 0; k < q1; k++) {
                if (b[i] == a[k]) {
                    p = 1;
                }
            }

        }
    }

    printf("\nFaults = %d\n", m);

    return 0;
}
