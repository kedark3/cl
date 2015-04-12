#include<stdio.h>

int i,j,k,n,co,p[20],ele[20],ch,ini;

void print()
{
	printf("\nNode\tStatus");
	printf("\n=======================");
	for(i=1;i<=n;i++)
		if(p[i]==1)
			printf("\n%d\tLive",i);
		else
			printf("\n%d\tDead",i);
	
	printf("\n=======================");
}

void election(int init)
{
	int max=0;
	j=0;
	i=init;
	ele[j++]=i;
	do
	{

		if(p[i+1]==1)
		{
			printf("\nElection message:%d-->%d",i,i+1);
			ele[j++]=i+1;
		}
		printf("\nElection array:--->{");
		for(k=0;k<j;k++)
			printf("%d,",ele[k]);
		printf("}\n");
		i++;
		if(i==n)
			i=0;
	}while(init!=i);
	for(i=0;i<j;i++)
	{
		if(ele[i]>max)
			max=ele[i];
	}
	co=max;
	printf("\nNew Coordinator:\t%d",co);
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
