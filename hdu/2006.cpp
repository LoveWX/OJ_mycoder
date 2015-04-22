#include<stdio.h>

int main()
{
	int n,p,t;
	while(scanf("%d",&n)!=EOF)
	{
		p=1;
		while(n-->0)
		{
			scanf("%d",&t);
			if(t%2==1)
				p*=t;
		}
		printf("%d\n",p);
	}
	return 0;
}