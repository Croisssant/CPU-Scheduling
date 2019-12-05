#include<stdio.h> 
#include"FCFS.c"
#include"RoundRobin.c"

int main() 
{ 
	//Define No of Processes
	int processes[] = { 1, 2, 3}; 
	int n = sizeof processes / sizeof processes[0]; 
	
	//Burst time of all processes 
	int burst_time[] = {2, 5, 6,};

	// Arrival Time 
	int at[] = {0, 1, 2};
	
	int choice, time_quantum;
	printf("Select the CPU Scheduling Algorithm you desire:\n");
	printf("1: First Come First Serve\n");
	printf("2: Round Robin\n");
	printf("3: Multilevel Feedback Queue\n");
	printf(">> ");
	scanf("%d", &choice);
	
	
	switch (choice){
		case 1:
			FCFS(processes, n, burst_time, at); 
			break;
		
		case 2:
			printf("Please insert the Time Quantum\n");
			printf(">> ");
			scanf("%d", &time_quantum);
			RR(burst_time, at, n, time_quantum);
			break;
		
		case 3:
			printf("MLFQ");
			break;

		default:
			printf("Something is wrong");
			break;
	}
	
	return 0; 

} 
