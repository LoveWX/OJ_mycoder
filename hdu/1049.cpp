#include<stdio.h>

int main()
{
	int n,u,d,step;
	while(1)
	{
		scanf("%d%d%d",&n,&u,&d);
		if(n==0)
			break;
		step=(n-u)/(u-d)*2;
		n=u+(n-u)%(u-d);
		while(n>0)
		{
			if(n<=u)
			{
				step++;
				break;
			}
			else
			{
				n=n-u+d;
				step++;
				step++;
			}
		}
		printf("%d\n",step);
	}
	return 0;
}
