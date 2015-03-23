#include<stdio.h>
#include<unistd.h>
//Index will act as priority number while value 1:Live,0:Dead
int node[50],n;
void print_status()
{
	int i;
	printf("\n\n\n************************");
	printf("\nNode\tstatus");
	for(i=1;i<=n;i++)
		if(node[i]==1)
			printf("\n%d\tLive",i);
		else
			printf("\n%d\tDead",i);
}
int poll(int k)
{
	if(node[k]==1)
		return 1;
	else
		return 0;
}
void bully()
{
	int c,elector=0,e1,v,i;
	printf("\nAs %dth node crashed, we will hold the election....",n);

	do{
		elector=rand()%n;
	}while(elector>n);
	printf("\nElector is:%d\n",elector);
	i=0;
	i=elector+1;
	while(i<=n)
	{
		v=poll(i);
		if(v==1)
			e1=i;
		i++;
	}
	printf("\nNow, after election, the coordinator is:%d",e1);
/*	do{
		c=rand()%n;
	}while(c>=n);*/
	c=e1;
	printf("\nNew crashed node is %d",c);
	node[c]=0;
	print_status();
	
	
	do{
		elector=rand()%n;
	}while(elector>n && node[elector]!=0);
	printf("\nElector is:%d\n",elector);
	i=0;
	i=elector+1;
	
	while(i<=n)
	{
		v=poll(i);
		if(v==1)
			e1=i;
		i++;
	}
	printf("\nNow, after election, the coordinator is:%d",e1);
	

}
int main()
{
	int i;
	
	printf("\nEnter no. of nodes:");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		node[i]=1;
	printf("\nInitially...");
	print_status();
	printf("\nCurrently Coordinator is:%dth Node",n);
	for(i=0;i<3;i++)
	{
		sleep(2);
		print_status();
	}
	
	printf("\nNode %d crashed!",n);
	node[n]=0;
	print_status();	
	bully();
}
		
		

