#include<stdio.h>

int grid[100][100];
int visit[100],dis[100];

int main()
{
	int n,i,j,min,pos;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&grid[i][j]);
			visit[i]=0;
			dis[i]=32767;
		}
		visit[0]=1;
		dis[0]=0;
		min=32767;
		for(i=1;i<n;i++)
			if(grid[0][i]>0)
			{
				dis[i]=grid[0][i];
				if(dis[i]<min)
				{
					min=dis[i];
					pos=i;
				}
			}
		while(pos!=n-1)
		{
			visit[pos]=1;
			min=32767;
			for(i=0;i<n;i++)
				if(visit[i]==0&&grid[pos][i]>0&&grid[pos][i]+dis[pos]<dis[i])
					dis[i]=grid[pos][i]+dis[pos];
			for(i=0;i<n;i++)
				if(visit[i]==0&&dis[i]<min)
				{
					min=dis[i];
					pos=i;
				}
		}
		printf("%d\n",dis[pos]);
	}
	return 0;
}