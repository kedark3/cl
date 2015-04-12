#include<stdio.h>
int p[20],n,co,ini,cnt,nwini,i,j,ch;
void print()
{	
	int i;
	printf("\nNode\tStatus");
	for(i=1;i<=n;i++)
	{
		if(p[i]==1)
			printf("\n%d\tLive",i);
		else
			printf("\n%d\tDead",i);
	}
}
void election(int ini)
{

	while(1){
		for(i=ini+1;i<=n;i++)
		{
			if(p[i]==1)
			{
				printf("\nElection Message from %d --> %d",ini,i);
			}
		}
		cnt=0;
		for(i=n;i>ini;i--)
		{
			if(p[i]==1)
			{
				printf("\nOk message from %d to --> %d",i,ini);
				nwini=i;
				cnt++;
			}
		}
		if(cnt==0)
		break;
		ini=nwini;
	
	}
	co=ini;
	printf("\nCurrent Coordinator is :%d",co);
	for(i=co-1;i>0;i--)
	{
		if(p[i]==1)
			printf("\nCoordinator intimation: %d-->%d",co,i);
	}
}
void main()
{

	
	printf("\nEnter No. of nodes:");
	scanf("%d",&n);
	
	printf("\nInitially all nodes are considered to be live!!!");
	for(i=1;i<=n;i++)
		p[i]=1;
	print();
	co=n;		
	while(1)
	{
		printf("\n1.Current Coordinator\n2.Crash Coordinator\n3.Recover Node\nEnter Choice:\t");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			printf("\nCurrent Coordinator is :%d",co);
			break;
			
			case 2:
			p[co]=0;
			print();
			printf("\nEnter the initiator:\t");
			scanf("%d",&ini);
			election(ini);
			break;
				
			case 3:
			print();
			printf("\n Enter node to be recovered:\t");
			scanf("%d",&ch);
			p[ch]=1;
			if(ch>co)
				election(ch);
				
			break;
		}
	}
}
