#include<stdio.h>

int main()
{
	int n,m,t,first;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0)
			break;
		first=1;
		while(n-->0)
		{
			scanf("%d",&t);
			if(t>=m)
			{
				printf("%d %d",m,t);
				first=0;
				break;
			}
			printf("%d ",t);
		}
		while(n-->0)
		{
			scanf("%d",&t);
			printf(" %d",t);
		}
		if(first==1)
			printf("%d",m);
		printf("\n");
	}
	return 0;
}