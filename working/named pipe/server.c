#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
int main()
{
	int file1,ch;
	FILE *fifoclient,*fifoserver;
	char *buff;
	
	file1=mkfifo("fifo_server",0666);

	if(file1<0)
		printf("\nError Creating pipe!");
	else
		printf("\n Pipe created!");
	for(;;)
	{

		fifoclient=fopen("fifo_client","r");
		if(fifoclient==NULL)
			printf("\nError opening fifo_client!");
		else
			printf("\n File opened!");
		
		fread(&ch,sizeof(ch),sizeof(ch),fifoclient);
		fifoserver=fopen("fifo_server","w");
		if(fifoserver== NULL )
			printf("\nError opening fifo_client!");
		else
			printf("\n File opened!");
		
		printf("\n Choice is %d",ch);
		switch(ch)
		{
			case 1:buff="OS NAME";
			break;
			case 2:buff="Kernel Version";
			break;
			case 3:buff="OS Distribution";
			break;
			default:buff="Wrong Choice, try again";
			
		}
		fwrite(&buff,sizeof(buff),sizeof(buff),fifoserver);
		printf("\nServer has sent response...");
	
	}
	
}
