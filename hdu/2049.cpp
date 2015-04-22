#include<stdio.h>

int main()
{
	int n,m,i;
	__int64 p[21]={1,1,2};
	__int64 a[21]={0,0,1};
	for(n=3;n<=20;n++)
	{
		p[n]=n*p[n-1];
		a[n]=(n-1)*(a[n-1]+a[n-2]);
	}
	while(scanf("%d",&i)!=EOF)
	{
		while(i-->0)
		{
			scanf("%d%d",&n,&m);
			printf("%I64d\n",a[m]*(p[n]/(p[m]*p[n-m])));
		}
	}
	return 0;
}