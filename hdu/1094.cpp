#include<stdio.h>

int main()
{
	int n,t,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		while(n>0)
		{
			scanf("%d",&t);
			sum+=t;
			n--;
		}
		printf("%d\n",sum);
	}
	return 0;
}