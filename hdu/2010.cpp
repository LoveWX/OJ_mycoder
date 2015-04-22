#include<stdio.h>

int main()
{
	int m,n,flag;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		flag=0;
		if(m<=153&&153<=n)
		{
			printf("153");
			flag=1;
		}
		if(m<=370&&370<=n)
		{
			if(flag==1)
				printf(" ");
			printf("370");
			flag=1;
		}
		if(m<=371&&371<=n)
		{
			if(flag==1)
				printf(" ");
			printf("371");
			flag=1;
		}
		if(m<=407&&407<=n)
		{
			if(flag==1)
				printf(" ");
			printf("407");
			flag=1;
		}
		if(flag==0)
			printf("no");
		printf("\n");
	}
	return 0;
}