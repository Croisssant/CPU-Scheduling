#include<stdio.h> 
#include"FCFS.c"
#include"RoundRobin.c"
#include "MLFQ.c"

int main() 
{ 
	// define number of processes
	int processes[] = {1, 2, 3, 4, 5}; 
	int n = sizeof processes / sizeof processes[0]; 

	// burst time of all processes 
	int burstTime1[] = {25, 2, 4, 6, 5};
	int burstTime2[] = {6, 8, 4, 10, 12};

	// arrival Time 
	int arrivalTime1[] = {0, 2, 4, 6, 8};
	int arrivalTime2[] = {0, 0, 0, 0, 0};
	
	int choice, timeQuantum;
	printf("Select the CPU Scheduling Algorithm you desire:\n");
	printf("1: First Come First Serve\n");
	printf("2: Round Robin\n");
	printf("3: Multilevel Feedback Queue\n");
	printf(">> ");
	scanf("%d", &choice);
	
	
	switch (choice){
		case 1:
			FCFS(processes, n, burstTime1, arrivalTime1); 
			break;
		
		case 2:
			printf("Please insert the Time Quantum\n");
			printf(">> ");
			scanf("%d", &timeQuantum);
			RR(n, burstTime1, arrivalTime1,timeQuantum);
			break;
		
		case 3:
			printf("Please insert the Time Quantum\n");
			printf(">> ");
			scanf("%d", &timeQuantum);
			MLFQ(arrivalTime1, burstTime1, n, timeQuantum);
			break;

		default:
			printf("Something is wrong");
			break;
	}
	return 0; 
} 