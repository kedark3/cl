#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHMSZ 1024
void main()
{
	int shm_id;
	key_t key;
	char *shm, *s;
	
	key = 5678;
	shm_id=shmget(key, SHMSZ, 0666|IPC_CREAT);
	if(shm_id == -1)
	{
		printf("\nError in creating memory!\n");
		exit(0);
	}
	shm= shmat(shm_id,NULL,0);
	s=shm;
	printf("\nEnter String:\t");
	gets(s);
//	puts(s);

	while(1)
	{
		for(s=shm; *s!='\0';s++)
		{
			//putchar(*s);
			if(*s=='#')
			{
				printf("\nClient Read the content from memory!!");
				exit(0);
			}
		}
		
		sleep(5);
	}
	shmdt(shm);
	shmctl(shm_id,IPC_RMID,NULL);
	
			
}

/*Output:
sairam@sairam-VPCEH28FN:~$ gcc server.c -o server
server.c: In function ‘main’:
server.c:18:3: warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
   exit(0);
   ^
server.c:23:2: warning: ‘gets’ is deprecated (declared at /usr/include/stdio.h:638) [-Wdeprecated-declarations]
  gets(s);
  ^
server.c:34:5: warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
     exit(0);
     ^
/tmp/ccUI3yIy.o: In function `main':
server.c:(.text+0x8c): warning: the `gets' function is dangerous and should not be used.
sairam@sairam-VPCEH28FN:~$
sairam@sairam-VPCEH28FN:~$ ./server

Enter String:	Kedar Kulkarni, MITCOE!

Client Read the content from memory!!sairam@sairam-VPCEH28FN:~$ 
*/
