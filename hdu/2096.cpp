#include<stdio.h>

int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			scanf("%d%d",&a,&b);
			a%=100;
			b%=100;
			printf("%d\n",(a+b)%100);
		}
	}
	return 0;
}