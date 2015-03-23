#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char * clientfifo = "/tmp/clientfifo";
    char * serverfifo = "/tmp/serverfifo";
    char buf[MAX_BUF];
    mkfifo(clientfifo, 0666);
    /* open, read, and display the message from the FIFO */
    for(;;)
    {
    	fd = open(serverfifo, O_RDONLY);
    	read(fd, buf, MAX_BUF);
    	printf("Received: %s\n", buf);
    	close(fd);
    }
    return 0;
}


