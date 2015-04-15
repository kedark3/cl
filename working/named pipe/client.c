#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
int main()
{
	int file1,ch;
	FILE *fifoclient,*fifoserver;
	char *buff;
	
	file1=mkfifo("fifo_client",0666);
	
	if(file1<0)
		printf("\nError Creating pipe!");
	
	for(;;)
	{
		printf("\n1.OS Name \n2.Kernel Version \n3.OS Distribution");
		printf("\nEnter your Choice:\t");
		scanf("%d",&ch);
		fifoclient=fopen("fifo_client","w+");
		if(fifoclient==NULL)
			printf("\nError opening fifo_client!");
		
		fwrite(&ch,sizeof(ch),sizeof(ch),fifoclient);
		fifoserver=fopen("fifo_server","r");
		fread(&buff,sizeof(buff),sizeof(buff),fifoserver);
		
		printf("\nResponse from Server:%s",buff);
	}
	
}
