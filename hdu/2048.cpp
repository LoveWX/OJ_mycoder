#include<stdio.h>

int main()
{
	int n,c;
	__int64 a[21]={0,0,1},b[21]={1,1,2};
	for(n=3;n<21;n++)
	{
		a[n]=(n-1)*(a[n-1]+a[n-2]);
		b[n]=n*b[n-1];
	}
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			scanf("%d",&c);
			printf("%.2lf%%\n",(double)a[c]/b[c]*100);
		}
	}
	return 0;
}