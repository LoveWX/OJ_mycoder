#include<stdio.h>

int main()
{
	int n,m,sum,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		sum=0;
		while(n-->0)
		{
			scanf("%d%d",&a,&b);
			if(b>a)
				a=b-a-1;
			else
				a=a-b-1;
			sum^=a;
		}
		if(sum>0)
			printf("I WIN!\n");
		else
			printf("BAD LUCK!\n");
	}
	return 0;
}