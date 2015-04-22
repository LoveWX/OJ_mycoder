#include<stdio.h>
#define SIZE 101
#define MAXINT 2147483647

int grid[SIZE][SIZE];
int visited[SIZE];
int dis[SIZE];
int n;

void visit(int s)
{
	if(visited[s]==1)
		return;
	visited[s]=1;
	int i;
	for(i=1;i<s;i++)
		if(grid[s][i]>0)
			visit(i);
	for(i=s+1;i<=n;i++)
		if(grid[s][i]>0)
			visit(i);
}

int checkpath()
{
	int i;
	visit(1);
	for(i=1;i<=n;i++)
		if(visited[i]==0)
			return 0;
	return 1;	
}

int main()
{
	int i,j,m,nextpoint,d,sum;
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(m==0)
			break;
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
			for(j=1;j<=n;j++)
				grid[i][j]=0;
		}
		while(m-->0)
		{
			scanf("%d%d%d",&i,&j,&d);
			if(grid[i][j]==0)
			{
				grid[i][j]=d;
				grid[j][i]=d;
			}
			else
			{
				if(grid[i][j]>d)
				{
					grid[i][j]=d;
					grid[j][i]=d;
				}
			}
		}
		if(checkpath()==0)
		{
			printf("?\n");
			continue;
		}
		visited[1]=1;
		for(i=2;i<=n;i++)
		{
			visited[i]=0;
			dis[i]=grid[1][i];
			if(dis[i]==0)
				dis[i]=MAXINT;
		}
		m=n-1;
		sum=0;
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
			sum+=dis[nextpoint];
			for(i=1;i<=n;i++)
				if(visited[i]==0)
					if(grid[i][nextpoint]>0&&grid[i][nextpoint]<dis[i])
						dis[i]=grid[i][nextpoint];
		}
		printf("%d\n",sum);
	}
	return 0;
}
