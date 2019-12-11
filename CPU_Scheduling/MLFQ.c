#include<stdio.h>

struct process
{
    char name;
    int AT,BT,WT,TAT,RT,CT;
}

Q1[10],Q2[10];/*Three queues*/

int n;
void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            {
                if(Q1[i].AT>Q1[j].AT)
                    {
                        temp=Q1[i];
                        Q1[i]=Q1[j];
                        Q1[j]=temp;
                    }
            }
    }
}

int MLFQ(int at[], int bt[], int n, int timeQuantum)
{
    int i,j,k=0,r=0,time=0,flag=0;
    char c;
   
    for (i=0,c='A'; i<=n; i++,c++){
    Q1[i].name=c;
    Q1[i].AT = at[i];
    Q1[i].BT = bt[i];
    Q1[i].RT=Q1[i].BT;/*save burst time in remaining time for each process*/
    }
    
    sortByArrival();
    time=Q1[0].AT;
    printf("Process in first queue following RR with qt=5");
    printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
    for(i=0;i<n;i++)
    {

        if(Q1[i].RT<=timeQuantum)
        {

            time+=Q1[i].RT;/*from arrival time of first process to completion of this process*/
            Q1[i].RT=0;
            Q1[i].WT=time-Q1[i].AT-Q1[i].BT;/*amount of time process has been waiting in the first queue*/
            Q1[i].TAT=time-Q1[i].AT;/*amount of time to execute the process*/
            printf("\n%c\t\t%d\t\t%d\t\t%d",Q1[i].name,Q1[i].BT,Q1[i].WT,Q1[i].TAT);

        }
        else/*process moves to queue 2 with qt=8*/
        {
            Q2[k].AT=time;
            time+=timeQuantum;
            Q1[i].RT-=timeQuantum;
            Q2[k].BT=Q1[i].RT;
            Q2[k].RT=Q2[k].BT;
            Q2[k].name=Q1[i].name;
            k=k+1;
            flag=1;
        }
    }
    // if(flag==1)
    // {
    //     printf("\nProcess in second queue following RR with qt=8");
    //     printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
    // }
    // for(i=0;i<k;i++)
    // {
    //     if(Q2[i].RT<=tq2)
    //     {
    //     time+=Q2[i].RT;/*from arrival time of first process +BT of this process*/
    //     Q2[i].RT=0;
    //     Q2[i].WT=time-timeQuantum-Q2[i].BT;/*amount of time process has been waiting in the ready queue*/
    //     Q2[i].TAT=time-Q2[i].AT;/*amount of time to execute the process*/
    //     printf("\n%c\t\t%d\t\t%d\t\t%d",Q2[i].name,Q2[i].BT,Q2[i].WT,Q2[i].TAT);

    //     }
    //     else/*process moves to queue 3 with FCFS*/
    //     {
    //     Q3[r].AT=time;
    //     time+=tq2;
    //     Q2[i].RT-=tq2;
    //     Q3[r].BT=Q2[i].RT;
    //     Q3[r].RT=Q3[r].BT;
    //     Q3[r].name=Q2[i].name;
    //     r=r+1;
    //     flag=2;
    //     }
    // }

    
    if(flag==1)
    {
        printf("\nProcess in third queue following FCFS ");
        printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
    }
    
    for(i=0;i<k;i++)
    {
        if(i==0)
            Q2[i].CT=Q2[i+1].AT+Q2[i].RT;
        else
            Q2[i].CT=Q2[i-1].CT+Q2[i].BT+timeQuantum;
    }

    for(i=0;i<k;i++)
    {
        Q2[i].TAT=Q2[i].CT;
        Q2[i].WT=Q2[i].TAT-Q2[i].BT-timeQuantum;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t",Q2[i].name,Q2[i].BT,Q2[i].WT,Q2[i].TAT);
    }
}