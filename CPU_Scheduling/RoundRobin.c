// Implementation for RoundRobin Scheduling

#include<stdio.h> 
  
// function to find the waiting time for all processes 
void RR_WT(int n, int bt[], int wt[], int at[], int quantum) 
{ 
  int i,time, rem_bt[n], flag=0;
  int remain = n;

    // make a copy of burst times bt[] to store remaining burst times. 
  for(i = 0; i < n; i++)
  {
    rem_bt[i] = bt[i];
  }

  for(time=0,i=0;remain!=0;) 
  { 
    if(rem_bt[i] <= quantum && rem_bt[i]>0) 
    { 
      time += rem_bt[i]; 
      rem_bt[i]=0; 
      flag=1; 
    } 
    else if(rem_bt[i]>0) 
    { 
      rem_bt[i] -= quantum; 
      time += quantum; 
    } 
    if(rem_bt[i]==0 && flag==1) 
    { 
      remain--; 
      wt[i] = time - at[i] - bt[i];
      flag=0; 
    } 
    if(i == n-1) 
      i = 0; 
    else if(at[i+1] <= time) 
      i++; 
    else 
      i=0; 
  }
}
  
// function to calculate turn around time 
void RR_TAT(int n, int bt[], int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 

// function to calculate average time 
void RR(int n, int bt[], int at[], int quantum) 
{ 
  int wt[n], tat[n];
  int total_wt = 0, total_tat = 0; 

  // function to find waiting time of all processes 
  RR_WT(n, bt, wt, at, quantum); 

  // function to find turn around time for all processes 
  RR_TAT(n, bt, wt, tat); 

  // display processes along with all details 
  printf("\n");
	printf("Processes\tBurst time\tArrival Time\tWaiting time\tTurn around time\n"); 

  // calculate total waiting time and total turn around time 
  float total_bt = 0;
  for(int i=0;i<n;i++)
	{
    total_bt += bt[i];
    total_wt = total_wt + wt[i]; 
    total_tat = total_tat + tat[i]; 
		printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1, bt[i], at[i], wt[i], tat[i]);
	}
    printf("Average waiting time = %.2f\n",(float)total_wt / (float)n); 
    printf("Average turn around time = %.2f\n",(float)total_tat / (float)n);
    float throughput = (float)n / (float)total_bt;
    printf("Throughput = %f\n", throughput);
} 