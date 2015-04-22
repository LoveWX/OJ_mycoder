#include<stdio.h>

int main()
{
	long m;
	int n,t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		scanf("%ld",&m);
		n=m%10;
		if(n==1||n==5||n==6||n==9||n==0)
		{
			printf("%ld\n",n);
			continue;
		}
		if(n==4)
		{
			printf("6\n");
			continue;
		}
		if(n==2||n==8)
		{
			if(m%4==2)
				printf("4\n");
			else
				printf("6\n");
		}
		if(n==3)
		{
			if((m-1)%4==0)
				printf("3\n");
			else
				printf("7\n");
		}
		if(n==7)
		{
			if((m-1)%4==0)
				printf("7\n");
			else
				printf("3\n");
		}
	}
	return 0;
}