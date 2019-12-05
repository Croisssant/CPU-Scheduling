#include<stdio.h> 
void RR(int bt[], int at[], int n, int time_quantum){
  int wait_time=0,turnaround_time=0,rt[n]; 
  int j,time,remain,flag=0; 
  int count;
  remain=n;
  for(int i=0; i<=n; i++){
    rt[i]=bt[i];
  }

  printf("\nProcess\t\tWaiting Time\tTurnaround Time\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("%d\t\t%d\t\t%d\n",count+1,time-at[count]-bt[count],time-at[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
    count=0; 
    else if(at[count+1]<=time) 
    count++; 
    else 
    count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 

}