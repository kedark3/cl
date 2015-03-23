#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
    int fd,ch;
    char * clientfifo = "/tmp/clientfifo";
    char * serverfifo = "/tmp/serverfifo";
    char buf[MAX_BUF];
    mkfifo(clientfifo, 0666);
    /* open, read, and display the message from the FIFO */
    for(;;)
    {
	printf("\n1.OS Name \n2.Kernel Version \n3.OS Distribution");
	printf("\nEnter your Choice:\t");
	scanf("%d",&ch);
	fd = open(clientfifo, O_WRONLY);
	write(fd, &ch, sizeof(ch));
	close(fd);
    	fd = open(serverfifo, O_RDONLY);
    	read(fd, buf, MAX_BUF);
    	printf("We Received: %s\n", buf);
    	close(fd);
    }
    return 0;
}

/*
Output:
sairam@sairam-VPCEH28FN:~$ gcc client1.c -o client
sairam@sairam-VPCEH28FN:~$ ./client

1.OS Name 
2.Kernel Version 
3.OS Distribution
Enter your Choice:	1
We Received: Ubuntu 14.04.1 LTS


1.OS Name 
2.Kernel Version 
3.OS Distribution
Enter your Choice:	2
We Received: 3.13.0-43-generic


1.OS Name 
2.Kernel Version 
3.OS Distribution
Enter your Choice:	3
We Received: Linux version 3.13.0-43-generic (buildd@akateko) (gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1) ) #72-Ubuntu SMP Mon Dec 8 19:35:44 UTC 2014


1.OS Name 
2.Kernel Version 
3.OS Distribution
Enter your Choice:	^C
sairam@sairam-VPCEH28FN:~$ 
*/
