#include<stdio.h>

int main()
{
	int n;
	__int64 a[51]={0,3,6,6};
	for(n=4;n<=50;n++)
		a[n]=a[n-1]+a[n-2]+a[n-2];
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",a[n]);
    return 0;
}