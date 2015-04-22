#include<stdio.h>

int main()
{
	int i,j;
	__int64 a[21][21]={0};
	for(i=1;i<=20;i++)
	{
		a[i][0]=1;
		for(j=1;j<=i;j++)
			a[i][j]=a[i-1][j]+a[i][j-1];
	}
	while(scanf("%d%d",&i,&j)!=EOF)
		printf("%I64d\n",a[i][j]);
	return 0;
}