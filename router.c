#include<stdio.h>

struct node
{
	unsigned dist[10];
	unsigned from[10];
}rt[10];

void main()
{
	int i,j,k,costmat[10][10],count,n;
	printf("enter no.of nodes\n");
	scanf("%d",&n);
	printf("enter cost matrix:\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		scanf("%d",&costmat[i][j]);
		costmat[i][i]=0;
		rt[i].dist[j]=costmat[i][j];
		rt[i].from[j]=j;
	}
	do
	{
		count=0;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		for(k=0;k<n;k++)
		{
			if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
			{
				rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
				rt[i].from[j]=j;
				count++;
			}
		}
	}while(count!=0);
	for(i=0;i<n;i++)
	{
		printf("for router %d\n",i+1);
		for(j=0;j<n;j++)
		{
			printf("node %d via %d dist %d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);		
		
		}
	}
}
