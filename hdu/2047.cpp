#include<stdio.h>

int main()
{
	int n;
	__int64 a[40]={0,3,8};
	for(n=3;n<40;n++)
		a[n]=a[n-1]+a[n-2]+a[n-1]+a[n-2];
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",a[n]);
	return 0;
}