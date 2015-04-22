#include<stdio.h>

int grid[100][100];
int visit[100],goin[100],queue[100];
int n;

int main()
{
	int i,j,flag,b,t;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			visit[i]=0;
			for(j=0;j<n;j++)
				scanf("%d",&grid[i][j]);
		}
		b=0;
		t=0;
		for(i=0;i<n;i++)
		{
			goin[i]=0;
			for(j=0;j<n;j++)
				goin[i]+=grid[j][i];
			if(goin[i]==0)
			{
				queue[t++]=i;
				visit[i]=1;
			}
		}
		while(t>b)
		{
			i=queue[b++];
			for(j=0;j<n;j++)
				if(grid[i][j]!=0)
					goin[j]--;
			for(j=0;j<n;j++)
				if(visit[j]==0&&goin[j]==0)
				{
					queue[t++]=j;
					visit[j]=1;
				}
		}
		flag=0;
		for(i=0;i<n;i++)
			if(visit[i]==0)
			{
				flag=1;
				break;
			}
		if(flag==1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}