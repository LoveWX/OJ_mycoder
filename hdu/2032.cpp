#include<stdio.h>

int main()
{
	int i,j,n;
	long g[31][31]={0};
	g[1][1]=1;
	for(i=2;i<=30;i++)
	{
		g[i][1]=1;
		for(j=1;j<=i;j++)
			g[i][j]=g[i-1][j]+g[i-1][j-1];
	}
	while(scanf("%d",&n)!=EOF)
	{
		for(j=1;j<=n;j++)
		{
			printf("1");
			for(i=2;i<=j;i++)
				printf(" %ld",g[j][i]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}