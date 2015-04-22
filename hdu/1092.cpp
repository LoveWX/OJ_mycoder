#include<stdio.h>

int main()
{
	int n,t,sum;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		scanf("%d",&sum);
		n--;
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