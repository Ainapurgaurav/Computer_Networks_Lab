#include<stdio.h>
#include<string.h>

int check(int fl)
{
	char in[100];
	int i,temp,n,sum=0;
	scanf("%s",in);
	
	if(strlen(in)%2!=0)
		n=(strlen(in)+1)/2;
	else
		n=strlen(in)/2;
		
	for(i=0;i<n;i++)
	{
		temp=in[i*2];
		temp=(temp*256)+in[(i*2)+1];
		sum+=temp;
	}
	
	if(fl==1)
	{
		printf("enter checksum value\n");
		scanf("%x",&temp);
		sum+=temp;
	}
	
	if((sum%65536)!=0)
	{
		n=sum%65536;
		sum=(sum/65536)+n;
	}
	
	sum=65535-sum;
	printf("%x\n",sum);
	return sum;
}

void main()
{
	int ch,sum;
	do
	{
	printf("\n1.encode\n2.decode\n3.exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	printf("enter string\n");
	sum=check(0);
	printf("checksum to append is %x",sum);
	break;
	case 2:
	printf("enter string\n");
	sum=check(1);
	if(sum!=0)
		printf("corrupted data\n");
	else
		printf("valid checksum");
	break;
	case 3:
	break;
	default:
	printf("enter valid choice");
	}
	}while(ch!=3);
	
}
