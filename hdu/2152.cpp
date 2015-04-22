#include<stdio.h>
#define M 101
int main()
{
	int i,j,k,a,b,n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0)
		{
			if(m==0)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}
		scanf("%d%d",&a,&b);
		int c1[M]={0},c2[M]={0};
		for(i=a;i<=b;i++)
			c1[i]=1;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			for(j=0;j<=m;j++)
				if(c1[j]>0)
					for(k=a;k<=b&&j+k<=m;k++)
						c2[j+k]+=c1[j];
			for(j=0;j<=m;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%d\n",c1[m]);
	}
	return 0;
}