#include<stdio.h>

void main()
{
	int t1[20],t2[20],i,j,k,dep[20][20],e1,e2;
	
	printf("\nEnter no. of events on both machines:\t");
	scanf("%d %d",&e1,&e2);
	
	printf("\nEnter Timestamp for events on m1:\n");
	for(i=0;i<e1;i++)
		scanf("%d",&t1[i]);
	printf("\nEnter Timestamp for events on m2:\n");
	for(i=0;i<e2;i++)
		scanf("%d",&t2[i]);
	
	printf("\nEnter dependency matrix:");
	printf("\ne1->e2 = 1 \ne2->e1 = -1 \n else 0");
	printf("\n");
	
	for(i=0;i<e2;i++)
		printf("\te2%d", i+1);
	for(i=0;i<e1;i++)
	{
		printf("\n e1%d \t",i+1);
		for(j=0;j<e2;j++)
			scanf("%d",&dep[i][j]);
	}
	
	for(i=0;i<e1;i++)
	{
		for(j=0;j<e2;j++)
		{
			if(dep[i][j]==1)
			{
				if(t2[j]<t1[i])
				{
					t2[j]=t1[i]+1;
					for(k=j+1;k<e2;k++)
					{
						t2[k]+=1;
					}
				}
			}
			else if(dep[i][j]==-1)
			{
				if(t1[i]<t2[j])
				{
					t1[i]=t2[j]+1;
					for(k=i+1;k<e1;k++)
						t1[k]+=1;
				}
			}
		}
	}
	printf("P1 : ");     //to print the outcome of Lamport Logical Clock
	for(i=0;i<e1;i++)
		printf("%d\t",t1[i]);

	printf("\n P2 : ");
	for(j=0;j<e2;j++)
		printf("%d\t",t2[j]);
 
}

