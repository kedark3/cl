/* ASSG : TO SIMULATE LAMPORT TIMESTAMPING METHOD
 */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20

typedef struct Process{
	int clockRate;
	int clockHistory[MAX];
	int messageSent[MAX/2],messageSentCount;
	int messageReceived[MAX/2],messageReceivedCount;
}Process;

int processCount;
Process process[5];
int clockCount;

void InitProcess()
{
	clockCount = 1;
	printf("\n\n Enter clock rates :");
	for(int i = 0; i < processCount; i++){

		printf("\n For processes %d : ",i);
		scanf("%d",&process[i].clockRate);

		process[i].clockHistory[0] = 0;

		process[i].messageSentCount = 0;
		process[i].messageSent[0] = -1;
		process[i].messageReceivedCount = 0;
		process[i].messageReceived[0] = -1;
	}
}

void Display()
{
	int messageSentCounter[MAX];
	int messageReceivedCounter[MAX];

	for(int i = 0; i < processCount; i++){
		messageSentCounter[i] = 0;
		messageReceivedCounter[i] = 0;
	}
	
	printf("\n\n Displaying all info :\n\n");
	for(i = 0; i < processCount; i++){
		printf("    P%d     ",i);
	}
	printf("\n------------------------------");

	for(int k = 0; k < clockCount; k++){
		printf("\n");

		for(int i = 0; i < processCount; i++){

			if(process[i].clockHistory[k] == process[i].messageReceived[messageReceivedCounter[i]]){
				printf("--> %2d",process[i].clockHistory[k]);
				++(messageReceivedCounter[i]);
			}
			else
				printf("    %2d",process[i].clockHistory[k]);

			if(process[i].clockHistory[k] == process[i].messageSent[messageSentCounter[i]]){
				printf(" --> ");
				++(messageSentCounter[i]);
			}
			else
				printf("     ");
		}
	}
}

void IncrementAllProcessClocks()
{
	for(int i = 0; i < processCount; i++){
		int oldTime = process[i].clockHistory[clockCount - 1];
		int incrementRate = process[i].clockRate;
		int newTime = oldTime + incrementRate;
		
		process[i].clockHistory[clockCount] = newTime;
	}
	++clockCount;
}

void Lamport_SendMessage()
{
	int sender,receiver;

	printf("\nEnter sender process no : ");
	scanf("%d",&sender);
				
	printf("Enter receiver process no : ");
	scanf("%d",&receiver);
	
	int sendingTime = process[sender].clockHistory[clockCount - 1];	
	process[sender].messageSent[process[sender].messageSentCount] = sendingTime;
	++(process[sender].messageSentCount);
	printf("\n\n Process %d sends message with sending time %d",sender,sendingTime);
	
	IncrementAllProcessClocks();
	printf("\n All clocks incremented.");
	
	int arrivalTime = process[receiver].clockHistory[clockCount - 1];	
	printf("\n Process %d receives message with arrival time %d",receiver,arrivalTime);
	getch();

	if(sendingTime >= arrivalTime){
		printf("\n");
		Display();
		printf("\n Message arrives at %d which is prior to time message was sent %d.",arrivalTime,sendingTime);
		printf("\n So receiver fast forwards its clock to be one more than sending time i.e %d.",sendingTime +1);
		arrivalTime = sendingTime + 1;
		getch();
	}
	
	process[receiver].messageReceived[process[receiver].messageReceivedCount] = arrivalTime;
	++(process[receiver].messageReceivedCount);
	process[receiver].clockHistory[clockCount - 1] = arrivalTime;
}

void main()
{
	int choice;
	clrscr();
	printf("\n\n Enter number of processes : ");
	scanf("%d",&processCount);

	InitProcess();

	while (1){
		Display();
		getch();

		clrscr();
		printf("\n  -----------------------------");
		printf("\n   Lamport Timestamping method");
		printf("\n  -----------------------------");		
		printf("\n\n1] Display all information");
		printf("\n2] Send a message");
		printf("\n3] Idle");
		printf("\n4] Exit");

		printf("\nEnter choice : ");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				break;
			case 2:
				Lamport_SendMessage();
				break;
			case 3:
				IncrementAllProcessClocks();
				break;
			case 4:
				exit(0);
		}
	}
}

/*	 OUTPUT 
	
 Enter number of processes : 3

 Enter clock rates :
	 For processes 0 : 6
	 For processes 1 : 8
	 For processes 2 : 10

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0

  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 3

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6          8         10

  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 2

Enter sender process no : 0
Enter receiver process no : 1


 Process 0 sends message with sending time 6
 All clocks incremented.
 Process 1 receives message with arrival time 16

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20

  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 3

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24         30
	
  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 2

Enter sender process no : 1
Enter receiver process no : 2

 Process 1 sends message with sending time 24
 All clocks incremented.
 Process 2 receives message with arrival time 40

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24 -->     30
    24         32     --> 40
	
  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 3

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24 -->     30
    24         32     --> 40
    30         40         50
	
  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 3

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24 -->     30
    24         32     --> 40
    30         40         50
    36         48         60
	
  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 2

Enter sender process no : 2
Enter receiver process no : 1

 Process 2 sends message with sending time 60
 All clocks incremented.
 Process 1 receives message with arrival time 56

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24 -->     30
    24         32     --> 40
    30         40         50
    36         48         60 -->
    42         56         70

 Message arrives at 56 which is prior to time message was sent 60.
 So receiver fast forwards its clock to be one more than sending time i.e 61.

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24 -->     30
    24         32     --> 40
    30         40         50
    36         48         60 -->
    42     --> 61         70
	
  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 3

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24 -->     30
    24         32     --> 40
    30         40         50
    36         48         60 -->
    42     --> 61         70
    48         69         80
	
  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 2

	Enter sender process no : 1
	Enter receiver process no : 0

	Process 1 sends message with sending time 69
	All clocks incremented.
	Process 0 receives message with arrival time 54

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24 -->     30
    24         32     --> 40
    30         40         50
    36         48         60 -->
    42     --> 61         70
    48         69 -->     80
    54         77         90

 Message arrives at 54 which is prior to time message was sent 69.
 So receiver fast forwards its clock to be one more than sending time i.e 70.

 Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24 -->     30
    24         32     --> 40
    30         40         50
    36         48         60 -->
    42     --> 61         70
    48         69 -->     80
--> 70         77         90

  -----------------------------
   Lamport Timestamping method
  -----------------------------
	1] Display all information
	2] Send a message
	3] Idle
	4] Exit
	Enter choice : 3

	Displaying all info :

    P0         P1         P2
------------------------------
     0          0          0
     6 -->      8         10
    12     --> 16         20
    18         24 -->     30
    24         32     --> 40
    30         40         50
    36         48         60 -->
    42     --> 61         70
    48         69 -->     80
--> 70         77         90
    76         85         100
*/
