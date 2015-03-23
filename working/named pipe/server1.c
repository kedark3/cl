#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main()
{
    int fd;
    char ch;
    char * serverfifo = "/tmp/serverfifo";

    /* create the FIFO (named pipe) */
    mkfifo(serverfifo, 0666);

    /* write "Hi" to the FIFO */
    fd = open(serverfifo, O_WRONLY);
    for(;;)
    {
    	printf("\n1.Os Name\n2.Kernal Version\n3.OS distribution");
    	scanf("%c",&ch);
    	write(fd, &ch, sizeof(ch));
    }    
    close(fd);
    /* remove the FIFO */
    unlink(serverfifo);

    return 0;
}
