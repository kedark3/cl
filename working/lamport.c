#include<stdio.h>
void main()
{
	int i,j,k,n1,n2,t1[10],t2[10],dep[10][10];
	printf("\nenter the number of events in each process:");
	scanf("%d%d",&n1,&n2);
	printf("\nenter the timestamp for first process:");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&t1[i]);
	}
	printf("\nenter the timestamp for second process:");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&t2[i]);
	}
	printf("\nenter the dependency matrix\n");
	for(i=0;i<n2;i++)
		printf("\te2%d",i);
	for(i=0;i<n1;i++)
	{	
		printf("\ne1%d",i);
		for(j=0;j<n2;j++)
		{
			scanf("%d",&dep[i][j]);
		}
	}
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(dep[i][j]==1)
			{
				if(t2[j]<t1[i]+1)
					t2[j]=t1[i]+1;
				for(k=j+1;k<n2;k++)
				{
					t2[k]=t2[k-1]+1;
				}
			}
			if(dep[i][j]==-1)
			{
				if(t1[i]<t2[j]+1)
					t1[i]=t2[j]+1;
				for(k=i+1;k<n1;k++)
				{
					t1[k]=t1[k-1]+1;
				}
			}
		}
	}

	printf("\np1\n");
	for(i=0;i<n1;i++)
	{
		printf("%d >> ",t1[i]);
	}
	printf("\np2\n");
	for(i=0;i<n2;i++)
	{
		printf("%d >> ",t2[i]);
	}
}
