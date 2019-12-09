#include<stdio.h> 
#include"FCFS.c"
#include"RoundRobin.c"

int main() 
{ 
	// define number of processes
	int processes[] = {1, 2, 3}; 
	int n = sizeof processes / sizeof processes[0]; 
	
	// burst time of all processes 
	int burstTime[] = {2, 5, 6};

	// arrival Time 
	int arrivalTime[] = {0, 1, 2};
	
	int choice, timeQuantum;
	printf("Select the CPU Scheduling Algorithm you desire:\n");
	printf("1: First Come First Serve\n");
	printf("2: Round Robin\n");
	printf("3: Multilevel Feedback Queue\n");
	printf(">> ");
	scanf("%d", &choice);
	
	
	switch (choice){
		case 1:
			FCFS(processes, n, burstTime, arrivalTime); 
			break;
		
		case 2:
			printf("Please insert the Time Quantum\n");
			printf(">> ");
			scanf("%d", &timeQuantum);
			RR(burstTime, arrivalTime, n, timeQuantum);
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