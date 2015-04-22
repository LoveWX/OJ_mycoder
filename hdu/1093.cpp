#include<stdio.h>

int main()
{
	int n,m,t,sum;
	while(scanf("%d",&n)!=EOF)
	{
		while(n>0)
		{
			scanf("%d",&m);
			sum=0;
			while(m>0)
			{
				scanf("%d",&t);
				sum+=t;
				m--;
			}
			printf("%d\n",sum);
			n--;
		}
	}
	return 0;
}