#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

bool bigger(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.first>b.first;
}

int grid[10][10];

int main()
{
	int ncase,n,i,j,t;
	pair<int,int> degree[10];
	scanf("%d",&ncase);
	while(ncase-->0)
	{
		scanf("%d",&n);
		t=0;
		for(i=0;i<n;i++)
		{
			degree[i].second=i;
			scanf("%d",&degree[i].first);
			t+=degree[i].first;
			for(j=0;j<n;j++)
				grid[i][j]=0;
		}
		sort(degree,degree+n,bigger);
		if(t%2==1)
		{
			printf("NO\n");
			if(ncase>0)
				printf("\n");
			continue;
		}
		i=0;
		j=1;
		while(1)
		{
			if(degree[i].first<=0)
				break;
			for(t=i+1;degree[i].first>0;degree[i].first--,t++)
			{
				degree[t].first--;
				if(degree[t].first<0)
				{
					j=0;
					break;
				}
				grid[degree[i].second][degree[t].second]=1;
				grid[degree[t].second][degree[i].second]=1;
			}
			if(j==0)
				break;
			i++;
			sort(degree+i,degree+n,bigger);
		}
		if(j==0)
		{
			printf("NO\n");
			if(ncase>0)
				printf("\n");
			continue;
		}
		printf("YES\n");
		for(i=0;i<n;i++)
		{
			printf("%d",grid[i][0]);
			for(j=1;j<n;j++)
				printf(" %d",grid[i][j]);
			printf("\n");
		}
		if(ncase>0)
			printf("\n");
	}
	return 0;
}
