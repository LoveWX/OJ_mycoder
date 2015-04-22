#include<stdio.h>

int g[8][8];

int main()
{
	int n,i,j,k;
	char ch;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			g[i][0]=0;
			g[n][i]=0;
			for(j=1;j<=n;j++)
			{
				scanf("%c",&ch);
				getchar();
				getchar();
				if(ch=='A')
					g[i][j]=1;
				else if(ch=='T')
					g[i][j]=10;
				else if(ch=='J')
					g[i][j]=11;
				else if(ch=='Q')
					g[i][j]=12;
				else if(ch=='K')
					g[i][j]=13;
				else
					g[i][j]=ch-'0';
			}
		}
		g[n][n]=0;
		for(k=n-2;k>=0;k--)
			for(i=k,j=1;i<n;i++,j++)
			{
				if(g[i+1][j]>g[i][j-1])
					g[i][j]+=g[i+1][j];
				else
					g[i][j]+=g[i][j-1];
			}
		for(k=2;k<=n;k++)
			for(i=0,j=k;j<=n;i++,j++)
			{
				if(g[i+1][j]>g[i][j-1])
					g[i][j]+=g[i+1][j];
				else
					g[i][j]+=g[i][j-1];
			}
		printf("%d\n",g[0][n]);
	}
	return 0;
}