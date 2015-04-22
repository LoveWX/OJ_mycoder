#include<stdio.h>

int main()
{
	int n,i;
	long a[41]={0,1,2};
	for(n=3;n<=40;n++)
		a[n]=a[n-1]+a[n-2];
	while(scanf("%d",&n)!=EOF)
		while(n-->0)
		{
			scanf("%d",&i);
			printf("%ld\n",a[i-1]);
		}
    return 0;
}