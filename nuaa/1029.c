#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%ld\n",n*(n-1)*(n-2)*(n-3)/24);
	}
	return 0;
}