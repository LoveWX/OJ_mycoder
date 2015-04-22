#include<stdio.h>

int main()
{
	long a[31]={0,4};
	int n,i;
	for(n=2;n<31;n++)
		a[n]=a[n-1]+a[n-1]-2;
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			scanf("%d",&i);
			printf("%ld\n",a[i]);
		}
	}
	return 0;
}