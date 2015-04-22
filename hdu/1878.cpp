#include<stdio.h>

#define SIZE 1001

int degree[SIZE];
int visited[SIZE];
int grid[SIZE][SIZE];
int n;

void visit(int current)
{
	if(visited[current]==1)
		return;
	visited[current]=1;
	int i;
	for(i=1;i<current;i++)
		if(grid[current][i]==1)
			visit(i);
	for(i=current+1;i<=n;i++)
		if(grid[current][i]==1)
			visit(i);
}

int main()
{
	int i,j,m;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			degree[i]=0;
			visited[i]=0;
			for(j=1;j<=n;j++)
				grid[i][j]=0;
		}
		while(m-->0)
		{
			scanf("%d%d",&i,&j);
			degree[i]++;
			degree[j]++;
			grid[i][j]=1;
			grid[j][i]=1;
		}
		visit(1);
		j=1;
		for(i=1;i<=n;i++)
			if(degree[i]%2==1||visited[i]==0)
			{
				j=0;
				break;
			}
		if(j==1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
