#include<stdio.h>

#define MIN(x,y) (x>y)?y:x

int main()
{
	int drop=0,count=0,cap,inp[10]={0},ch,nsec,i=0,orate,x;
	printf("enter bucket size:");
	scanf("%d",&cap);
	printf("enter output rate:");
	scanf("%d",&orate);
	do
	{
		printf("enter no of packets receiving at %d",i+1);
		scanf("%d",&inp[i]);
		i++;
		printf("enter 1 to continue 0 to exit\n");
		scanf("%d",&ch);
	}while(ch);
	nsec=i;
	for(i=0;count||i<nsec;i++)
	{
		printf("\nsecond\treceived\tsent\tdrop\tcount\n");
		printf("%d\t%d\t\t%d\t",i+1,inp[i],MIN((inp[i]+count),orate));
		if((x=inp[i]+count-orate)>0)
		{
			if(x>cap)
			{
				count=cap;
				drop=x-cap;
			}
			else
			{
				count=x;
				drop=0;
			}
		}
		else
		{
			count=0;
			drop=0;
		}
		printf("%d\t%d\n",drop,count);
	}	
}
