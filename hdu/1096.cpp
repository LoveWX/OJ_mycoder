#include<stdio.h>

int main()
{
	int n,t,m,sum;
	scanf("%d",&n);
	while(n>0)
	{
		sum=0;
		scanf("%d",&m);
		for(;m>0;m--)
		{
			scanf("%d",&t);
			sum+=t;
		}
		printf("%d\n",sum);
		if(n>1)
			printf("\n");
		n--;
	}
	return 0;
}