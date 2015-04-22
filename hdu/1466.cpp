#include<stdio.h>

int main()
{
	int n,i,j;
	int a[21][191]={0};
	a[1][0]=1;
	a[2][0]=1;
	a[2][1]=1;
	a[3][0]=1;
	a[3][2]=1;
	a[3][3]=1;
	for(n=4;n<=20;n++)
	{
		a[n][0]=1;
		for(i=n-1;i>=1;i--)
			for(j=i*(i-1)/2;j>=0;j--)
				if(a[i][j]==1)
					a[n][(n-i)*i+j]=1;
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("0");
		for(i=1;i<=n*(n-1)/2;i++)
			if(a[n][i]==1)
				printf(" %d",i);
		printf("\n");
	}
	return 0;
}