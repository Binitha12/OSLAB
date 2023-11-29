#include<stdio.h>

typedef struct process{
    int pid;
    int at;
    int bt;
    int wt;
    int ct;
    int tat;
}process;

int main()
{
    
    int n,ttat,twt;
    float avwt,avtat;
    printf("Enter the no of processes\n");
    scanf("%d",&n);
    struct process p[n];
    printf("Enter the arrival time,Burst Time of each\n");
    //printf("Process no           Arrival time        Burst Time\n ");
    for(int i=0;i<n;i++)
    {
        p[i].pid=i;
        printf("p[%d]",i);
        scanf("%d  %d",&p[i].at,&p[i].bt);
        printf("\n");

    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].at>p[j].at)
            {
                struct process temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    printf("Process ID    Arrival Time   Burst Time \n");
    {
        for(int i=0;i<n;i++)
        {
            printf("%d         %d         %d \n",p[i].pid,p[i].at,p[i].bt);
        }

    }


    p[0].wt=0;
    p[0].ct=p[0].bt + p[0].at;
    p[0].tat=p[0].bt+p[0].wt;
    ttat=p[0].tat;
    twt=p[0].wt;



for(int i=1;i<n;i++)
{
    p[i].wt=p[i-1].ct-p[i].at;
    p[i].tat=p[i].bt+p[i].wt;
 p[i].ct=p[i].tat+p[i].at;
 ttat=ttat+p[i].tat;
 twt=twt+p[i].wt;

}
avtat=(float)ttat/(float)n;
avwt=(float)twt/(float)n;
printf("Process ID   Arrival Time  Burst Time   CT     TAT     WT\n");

for(int i=0;i<n;i++)
{

    printf(" %d     %d      %d      %d      %d      %d      \n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

}
printf("Total wt is %d\n",twt);
printf("Total tat is %d\n",ttat);
printf("Average wt is %f\n",avwt);
printf("Average tat is %f\n",avtat);







}