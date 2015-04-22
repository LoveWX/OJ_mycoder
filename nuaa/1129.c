#include<stdio.h>

int main()
{
	int n;
	long int n1,n2,m,t;
	while(1)
	{
		scanf("%d %ld",&n,&m);
		if(n==0&&m==0)
			break;
		if(n<2)
		{
			printf("-1\n");
			continue;
		}
		n1=-1;
		n2=-1;
		for(;n>0;n--)
		{
			scanf("%ld",&t);
			if(t<m)
			{
				if(t>n1)
				{
					n2=n1;
					n1=t;
				}
				else if(t>n2)
					n2=t;
			}
		}
		printf("%ld\n",n2);
	}
	return 0;
}