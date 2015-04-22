#include<stdio.h>

int main()
{
	long ans;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			scanf("%ld",&ans);
			ans=ans*ans*2-ans+1;
			printf("%ld\n",ans);
		}
	}
	return 0;
}