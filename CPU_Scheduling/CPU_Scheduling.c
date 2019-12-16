#include<stdio.h> 
#include <conio.h> 
#include <stdlib.h>
#include"FCFS.c"
#include"RoundRobin.c"
#include"MLFQ.c"

int main() 
{ 
	int x = 1;
	while (x==1){
		// define number of processes
		int work_choice=0;
		int *processes; 
		int n = sizeof processes / sizeof processes[0]; 

		// burst time of all processes 
		int *burstTime;
		int burstTime1[] = {40, 8, 10, 16, 12};
		int burstTime2[] = {10, 21, 15, 14, 12};

		// arrival Time 
		int *customArrival;
		int arrivalTime[] = {0, 0, 0, 0, 0};
		

		printf("\nChoose the workload you wish to proceed with:\n");
		printf("1: First Workload\n");
		printf("   Process \t Burst Time \t Arrival Time\n");
		for (int i=0; i<5; i++){
			printf("   P%d\t\t %d\t\t %d\n", i+1, burstTime1[i], arrivalTime[i]);
		}
		printf("2: Second Workload\n");
		printf("   Process \t Burst Time \t Arrival Time\n");
		for (int i=0; i<5; i++){
			printf("   P%d\t\t %d\t\t %d\n", i+1, burstTime2[i], arrivalTime[i]);
		}
		printf("3: Custom Workload\n");
		printf("\n#: Press anything else to exit");
		printf("\n>> ");
		scanf("%d", &work_choice);

		if(work_choice==1){
			n=5;
			burstTime = malloc(n * sizeof(int));
			processes = malloc(n * sizeof(int));
			customArrival = arrivalTime;
			for (int i=0; i<n; i++){
				processes[i] = i+1;
				burstTime[i] = burstTime1[i];
			}
		}
		else if(work_choice==2){
			n=5;
			burstTime = malloc(n * sizeof(int));
			processes = malloc(n * sizeof(int));
			customArrival = arrivalTime;
			for (int i=0; i<n; i++){
				processes[i] = i+1;
				burstTime[i] = burstTime2[i];
			}
		}
		else if (work_choice == 3)
		{
			printf("Enter number of processes:");
			printf("\n>> ");
			scanf("%d",&n);
			burstTime = malloc(n * sizeof(int));
			processes = malloc(n * sizeof(int));
			customArrival = malloc(n * sizeof(int));
			for (int i=0; i<n; i++){
				processes[i] = i+1;
				printf("Process %d",i+1);
				printf("\n---------------\n");
				printf("Enter burst time of process:");
				printf("\n>> ");
				scanf("%d",&burstTime[i]);
				printf("Enter arrival time of process:");
				printf("\n>> ");
				scanf("%d",&customArrival[i]);
			}
			
		}
		else{
			x = 0;
			break;
		}
		
		int choice, timeQuantum;
		char ch;
		printf("\n\nSelect the CPU Scheduling Algorithm you desire:\n");
		printf("1: First Come First Serve\n");
		printf("2: Round Robin\n");
		printf("3: Multilevel Feedback Queue\n");
		printf("4: Exit\n");
		printf(">> ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				FCFS(processes, n, burstTime, customArrival);
				printf("\nPress ANYTHING to continue\n");
				getch(); 
				break;
			
			case 2:
				printf("Please insert the Time Quantum\n");
				printf(">> ");
				scanf("%d", &timeQuantum);
				RR(n, burstTime, customArrival,timeQuantum);
				printf("\nPress ANYTHING to continue\n");
				getch(); 
				break;
			
			case 3:
				printf("Please insert the Time Quantum\n");
				printf(">> ");
				scanf("%d", &timeQuantum);
				MLFQ(customArrival, burstTime, n, timeQuantum);
				printf("\nPress ANYTHING to continue\n");
				getch(); 
				break;
			
			case 4:
				printf("Exiting now\n");
				x = 0;
				break;
			
			default:
				printf("Select a proper choice");
				break;
		}
	}
	return 0; 
} 