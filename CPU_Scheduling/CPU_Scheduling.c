#include<stdio.h> 
#include"FCFS.c"
#include"RoundRobin.c"
#include"MLFQ.c"

int main() 
{ 
	int x = 1;
	while (x==1){
		// define number of processes
		int work_choice=0;
		int processes[] = {1, 2, 3, 4, 5}; 
		int n = sizeof processes / sizeof processes[0]; 

		// burst time of all processes 
		int burstTime[] = {4,13,20,29,42};
		int burstTime1[] = {25, 2, 4, 6, 5};
		int burstTime2[] = {6, 8, 4, 10, 12};

		// arrival Time 
		int arrivalTime[] = {0,0,0,0,0};
		int arrivalTime1[] = {0, 2, 4, 6, 8};
		int arrivalTime2[] = {0, 0, 0, 0, 0};
		
		printf("\nChoose the workload you wish to proceed with:\n");
		printf("1: First Workload\n");
		printf("  Process \t Burst Time \t Arrival Time\n");
		for (int i=0; i<n; i++){
			printf("  P%d\t\t    %d\t\t      %d\n", i+1, burstTime1[i], arrivalTime1[i]);
		}
		printf("2: Second Workload\n");
		printf("  Process \t Burst Time \t Arrival Time\n");
		for (int i=0; i<n; i++){
			printf("  P%d\t\t    %d\t\t      %d\n", i+1, burstTime2[i], arrivalTime2[i]);
		}
		printf("\n#: Press anything else to exit");
		printf("\n>> ");
		scanf("%d", &work_choice);

		if(work_choice==1){
			for (int i=0; i<n; i++){
				burstTime[i] = burstTime1[i];
			}
		}
		else if(work_choice==2){
			for (int i=0; i<n; i++){
				burstTime[i] = burstTime2[i];
			}
		}
		else{
			x = 0;
			break;
		}
		
	
		int choice, timeQuantum;
		printf("\n\nSelect the CPU Scheduling Algorithm you desire:\n");
		printf("1: First Come First Serve\n");
		printf("2: Round Robin\n");
		printf("3: Multilevel Feedback Queue\n");
		printf("4: Exit\n");
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
				RR(n, burstTime, arrivalTime,timeQuantum);
				break;
			
			case 3:
				printf("Please insert the Time Quantum\n");
				printf(">> ");
				scanf("%d", &timeQuantum);
				MLFQ(arrivalTime, burstTime, n, timeQuantum);
				break;
			
			case 4:
				printf("Exiting now\n");
				x = 0;
				break;
			
			default:
				printf("Select a proper");
				break;
		}
	}
	return 0; 
} 