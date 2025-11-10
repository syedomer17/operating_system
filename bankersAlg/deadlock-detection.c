#include<stdio.h>

void main()
{
    int found,flag,l,p[4][5],tp,c[4][5],i,j,k=0,m[5],r[5],a[5],temp[5],sum;
    printf("Enter total no of processes:\n");
    scanf("%d",&tp);

    printf("Enter claim matrix:\n");
    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            scanf("%d",&c[i][j]);

    printf("Enter allocation matrix:\n");
    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            scanf("%d",&p[i][j]);

    printf("Enter resource vector:\n");
    for(i=0;i<5;i++)
        scanf("%d",&r[i]);

    printf("Enter available vector:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
        temp[i]=a[i];
    }

    // find processes with zero allocation
    for(i=0;i<4;i++)
    {
        sum = 0;
        for(j=0;j<5;j++)
            sum += p[i][j];

        if(sum == 0)
        {
            m[k] = i;       // process can finish
            k++;
        }
    }

    // main logic
    for(i=0;i<4;i++)
    {
        for(l=0;l<k;l++)
        {
            if(i != m[l])
            {
                flag = 0;
                for(j=0;j<5;j++)
                {
                    if(c[i][j] > temp[j])
                    {
                        flag = 1; 
                        break;
                    }
                }

                if(flag == 0)
                {
                    int already = 0;                  
                    for(int x = 0; x < k; x++)
                        if(m[x] == i) already = 1;
                    if(already == 0)
                    {
                        m[k] = i;
                        k++;
                        for(j=0;j<5;j++)
                            temp[j] += p[i][j];
                    }
                }
            }
        }
    }

    printf("Deadlock causing processes are:\n");
    for(j=0;j<tp;j++)
    {
        found = 0;
        for(i=0;i<k;i++)
        {
            if(m[i] == j)
            {
                found = 1;    
                break;        
            }
        }
        if(found == 0)
            printf("%d\n",j);
    }
}
