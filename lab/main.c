#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,p[100],bt[100],tt[100],wt[100];
    printf("enter the number of process: \n");
    scanf("%d",&n);
    printf("Process Number: ");

        for(i=0;i<n; i++)
    {
        scanf("%d",&p[i]);
    }

    printf("enter burst time of the process: \n");


    for (i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }

    for (i=0;i<n;i++)
    {
        wt[0]= 0;
        tt[0]=bt[0];
        wt[i+1]=wt[i]+bt[i];
        tt[i+1]=wt[i+1]+bt[i+1];
    }

    printf("process burst_time witing time turnarround time: \n");
    for (i=0; i<n;i++)
    {
        printf("p%d \t %d \t\t %d \t %d \n", i, bt[i],wt[i],tt[i]);
    }
   // print Gantt chart
    puts(""); // Empty line
    puts("          GANTT CHART          ");
    puts("          ***********          ");
    print_gantt_chart(p, n);
   

    return 0;
}


