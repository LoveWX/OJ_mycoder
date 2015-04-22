#include<stdio.h>
#define SIZE 101
#define MAXINT 2147483647

int grid[SIZE][SIZE];
int visited[SIZE];
int dis[SIZE];

int main()
{
	int i,j,m,n,nextpoint,d,s;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		m=n*(n-1)/2;
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
			for(j=1;j<=n;j++)
				grid[i][j]=MAXINT;
			grid[i][i]=0;
		}
		while(m-->0)
		{
			scanf("%d%d%d%d",&i,&j,&d,&s);
			if(s==0)
			{
				grid[i][j]=d;
				grid[j][i]=d;
			}
			else
			{
				grid[i][j]=0;
				grid[j][i]=0;
			}
		}
		visited[1]=1;
		grid[1][1]=0;
		for(i=2;i<=n;i++)
		{
			dis[i]=grid[1][i];
		}
		m=n-1;
		s=0;
		while(m-->0)
		{
			d=MAXINT;
			nextpoint=1;
			for(i=2;i<=n;i++)
			{
				if(visited[i]==0)
				{
					if(dis[i]<d)
					{
						d=dis[i];
						nextpoint=i;	
					}
				}
			}
			visited[nextpoint]=1;
			s+=dis[nextpoint];
			for(i=1;i<=n;i++)
				if(visited[i]==0)
					if(grid[i][nextpoint]<dis[i])
						dis[i]=grid[i][nextpoint];
		}
		printf("%d\n",s);
	}
	return 0;
}
