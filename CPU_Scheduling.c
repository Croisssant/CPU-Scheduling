// C program for implementation of FCFS 
// scheduling 
#include<stdio.h> 
// Function to find the waiting time for all 
// processes 
void findWaitingTime(int processes[], int n, 
						int bt[], int wt[], int at[]) 
{ 
	int service_time[n]; 
    service_time[0] = 0;
	// waiting time for first process is 0 
	wt[0] = 0; 
	
	// calculating waiting time 
	for (int i = 1; i < n ; i++ ){
		service_time[i] = service_time[i-1] + bt[i-1]; 
		wt[i] = service_time[i] - at[i];  
		if (wt[i] < 0){
			wt[i] = 0;
		}
	}
} 
	
// Function to calculate turn around time 
void findTurnAroundTime( int processes[], int n, 
				int bt[], int wt[], int tat[]) 
{ 
	// calculating turnaround time by adding 
	// bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 
	
//Function to calculate average time 
void findavgTime( int processes[], int n, int bt[], int at[]) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0, total_bt = 0; 

	//Function to find waiting time of all processes 
	findWaitingTime(processes, n, bt, wt, at); 
	
	//Function to find turn around time for all processes 
	findTurnAroundTime(processes, n, bt, wt, tat); 
	
	//Display processes along with all details 
	printf("Processes\tBurst time\tArrival Time\tWaiting time\tTurn around time\n"); 
	
	// Calculate total waiting time and total turn 
	// around time 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i];
		total_bt += bt[i]; 
		printf(" %d\t",(i+1)); 
		printf("	 %d\t\t", bt[i] ); 
		printf("     %d\t",at[i]);
		printf("	 %d\t",wt[i] );
		printf("	 %d\n",tat[i] );	
	} 
	int s=(float)total_wt / (float)n; 
	int t=(float)total_tat / (float)n; 
	printf("Average waiting time = %d",s); 
	printf("\n"); 
	printf("Average turn around time = %d ",t);
	printf("\n");
	//Don't change position of Throughput
	//Throughtput = no. of jobs / final complete time
	float throughput = (float)n/(float)total_bt;
	printf("Throughput = %f", throughput);
} 
	
// Driver code 
int main() 
{ 
	//process id's 
	int processes[] = { 1, 2, 3}; 
	int n = sizeof processes / sizeof processes[0]; 
	
	//Burst time of all processes 
	int burst_time[] = {2, 5, 6,}; 
	int at[] = {0, 1, 2};
	findavgTime(processes, n, burst_time, at); 
	return 0; 
} 
// This code is contributed by Shivi_Aggarwal 
