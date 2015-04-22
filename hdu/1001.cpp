#include<stdio.h>

int main()
{
	__int64 n;
	while(scanf("%lld",&n)!=EOF)
	{
		n=n*(1+n);
		n=n>>1;
		printf("%lld\n\n",n);
	}
	return 0;
}