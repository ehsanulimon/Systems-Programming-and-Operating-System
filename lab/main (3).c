#include<stdio.h>
int main()
{
    int n,i,process[100],temp,sum=0,bt[100],tbt[100],wt[100],tt[100],tq,count=0;
    printf("number of process : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("process number and Burst time for process :");
        scanf("%d %d",&process[i],&bt[i]);
        tbt[i]=bt[i];
    }
    printf("Time quantum :");
    scanf("%d",&tq);
    while(1)
    {
        for(count=0,i=0;i<n;i++)
        {
            temp=tq;
            if(tbt[i]==0)
            {
                count++;
                continue;
            }
            if(tbt[i]>tq)
            {
                tbt[i]=tbt[i]-tq;
            }
            else if(tbt[i]<=tq)
            {
                temp=tbt[i];
                tbt[i]=0;
            }
            sum=sum+temp;
            tt[i]=sum;
        }
        if(count==n)
            break;
    }
    for(i=0;i<n;i++)
    {
        wt[i]=tt[i]-bt[i];
    }
    printf("Proces BurstTime WaitingTime TurnaroundTime\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n",process[i],bt[i],wt[i],tt[i]);
    }
    return 0;
}
