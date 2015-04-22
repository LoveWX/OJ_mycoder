#include<stdio.h>

int min(int x,int y,int z)
{
	if(x>y)
		x=y;
	if(x>z)
		x=z;
	return x;
}

int main()
{
	int x[500][500];
	int n,i,j,maxl,t;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&x[i][j]);
		maxl=0;
		for(j=0;j<n;j++)
			x[n-1][j]=1+x[n-1][j];
		for(i=n-2;i>=0;i--)
		{
			x[i][n-1]=1+x[i][n-1];
			for(j=n-2;j>=0;j--)
				if(x[i][j]==-1)
					x[i][j]=0;
				else
				{
					t=min(x[i+1][j],x[i][j+1],x[i+1][j+1])+1;
					x[i][j]=t;
					if(t>maxl)
						maxl=t;
				}		
		}
		printf("%d\n",maxl);
	}
	return 0;
}