#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
#include<stdio.h>
#define MAX_BUF 1024
int main()
{
    int fd,i;
    FILE *fp;
    char * serverfifo = "/tmp/serverfifo";
    char * clientfifo = "/tmp/clientfifo";
    char buf[MAX_BUF];
    /* create the FIFO (named pipe) */
    mkfifo(serverfifo, 0666);

    
    for(;;)
    {
	fd = open(clientfifo, O_RDONLY);
    	read(fd, buf, MAX_BUF);
	close(fd);
	fd = open(serverfifo, O_WRONLY);    
	i=buf[0];	
	switch(i)
	{
		case 1:
		fp=popen("lsb_release -ds","r");
		fgets(buf,MAX_BUF,fp);
		printf("\nServer sent: %s",buf);
		pclose(fp);
		break;
		case 2:
		fp=popen("uname -r","r");
		fgets(buf,MAX_BUF,fp);
		printf("\nServer sent: %s",buf);
		pclose(fp);
		break;
		
		case 3:
		fp=popen("cat /proc/version","r");
		fgets(buf,MAX_BUF,fp);
		printf("\nServer sent: %s",buf);
		pclose(fp);
		break;
		default:strcpy(buf,"Wrong Choice, try again");
		
	}
    	write(fd, &buf, sizeof(buf));
    }    
    close(fd);
    /* remove the FIFO */
    unlink(serverfifo);

    return 0;
}
/*Output:
sairam@sairam-VPCEH28FN:~$ gcc server1.c -o server
sairam@sairam-VPCEH28FN:~$ ./server

Server sent: Ubuntu 14.04.1 LTS

Server sent: 3.13.0-43-generic

Server sent: Linux version 3.13.0-43-generic (buildd@akateko) (gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1) ) #72-Ubuntu SMP Mon Dec 8 19:35:44 UTC 2014
^C
sairam@sairam-VPCEH28FN:~$ 


*/
