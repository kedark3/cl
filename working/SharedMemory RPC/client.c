#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#define SHMSZ 1024
void main()
{
	int shm_id,i;
	key_t key;
	char *shm, *s;
	
	key = 5678;
	shm_id=shmget(key, SHMSZ, 0666);
	if(shm_id == -1)
	{
		printf("\nError in creating memory!\n");
		exit(0);
	}
	shm= shmat(shm_id,NULL,0);
	
	printf("\n We read:\n");
	for(s=shm; *s!='\0';s++)
	{
		putchar(*s);
	}
	strcat(s,"#");
	printf("\n");
	shmdt(shm);
	shmctl(shm_id,IPC_RMID,NULL);
	
}

/*
Output:
sairam@sairam-VPCEH28FN:~$ gcc client.c -o client
sairam@sairam-VPCEH28FN:~$ ./client

 We read:
Kedar Kulkarni, MITCOE!
sairam@sairam-VPCEH28FN:~$ 
*/
