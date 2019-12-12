// Implementation for Multilevel Feedback Queue Scheduling

#include<stdio.h>

struct process
{
    int name;
    int AT,BT,WT,TAT,RT,CT;
}

// two ready queues
Q1[10],Q2[10];

// function to sort elements in queue
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
                temp  = Q1[i];
                Q1[i] = Q1[j];
                Q1[j] = temp;
            }
        }
    }
}

// function for multilevel feedback queue
int MLFQ(int at[], int bt[], int n, int timeQuantum)
{
    int i,j,k=0,time=0,flag=0;
    float total_wt = 0;
    float total_tat = 0;
    float total_bt = 0;
    char c;
   
    for(i=0,c='A'; i<n; i++,c++){
        total_bt += bt[i];
        Q1[i].name = i+1;
        Q1[i].AT = at[i];
        Q1[i].BT = bt[i];
        Q1[i].RT = Q1[i].BT; /*save burst time in remaining time for each process*/
    }
    
    sortByArrival();
    time = Q1[0].AT;
    printf("\nProcess in first queue following RR with Time Quantum = %d", timeQuantum);
    printf("\nProcess\t\tBT\t\tWT\t\tTAT\t\t");

    // process for round robin queue
    for(i=0;i<n;i++)
    {
        if(Q1[i].RT<=timeQuantum)
        {

            time += Q1[i].RT; /*from arrival time of first process to completion of this process*/
            Q1[i].RT = 0;
            Q1[i].WT = time-Q1[i].AT-Q1[i].BT; /*amount of time process has been waiting in the first queue*/
            Q1[i].TAT = time-Q1[i].AT; /*amount of time to execute the process*/
            total_wt += Q1[i].WT;
            total_tat += Q1[i].TAT;
            printf("\nP%d\t\t%d\t\t%d\t\t%d",Q1[i].name,Q1[i].BT,Q1[i].WT,Q1[i].TAT);
        }
        else /*process moves to FCFS queue*/
        {
            Q2[k].AT = Q1[i].AT;
            time += timeQuantum;
            Q1[i].RT -= timeQuantum;
            Q2[k].BT = Q1[i].RT;
            Q2[k].RT = Q2[k].BT;
            Q2[k].name = Q1[i].name;
            k = k+1;
            flag = 1;
        }
    }
    
    if(flag==1)
    {
        printf("\n\nProcess in second queue following FCFS ");
        printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
    }
    
    // process for FCFS queue
    for(i=0;i<k;i++)
    {
        if(i==0)
        {
            Q2[i].CT = time+Q2[i].RT;
        }
        else
        {
            Q2[i].CT = Q2[i-1].CT+Q2[i].BT;
        }
    }

    for(i=0;i<k;i++)
    {
        Q2[i].TAT = Q2[i].CT - Q2[i].AT;
        Q2[i].WT = Q2[i].TAT-Q2[i].BT-timeQuantum;
        total_wt += Q2[i].WT;
        total_tat += Q2[i].TAT;
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t",Q2[i].name,Q2[i].BT,Q2[i].WT,Q2[i].TAT);
    }

    printf("\n\nAverage Waiting Time = %f", total_wt/(float)n);
    printf("\nAverage Turn Around Time = %f", total_tat/(float)n);
    printf("\nThroughput = %f\n", n/total_bt);
}