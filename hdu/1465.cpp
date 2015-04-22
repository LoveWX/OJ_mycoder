#include<stdio.h>

int main()
{
	int n;
	__int64 a[21]={0,0,1};
	for(n=3;n<=20;n++)
		a[n]=(n-1)*(a[n-1]+a[n-2]);
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",a[n]);
	return 0;
}