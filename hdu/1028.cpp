#include<stdio.h>
#define M 121
int c1[M],c2[M];
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(i=0;i<=n;i++)
		{
			c1[i]=1;
			c2[i]=0;
		}
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=n;j++)
				for(k=0;k+j<=n;k+=i)
					c2[k+j]+=c1[j];
			for(j=0;j<=n;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%d\n",c1[n]);
	}
	return 0;
}