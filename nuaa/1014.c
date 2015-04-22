#include<stdio.h>

int g[50][50];
int arr[50];
int n,k;

void findway(int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(x==i)
			continue;
		if(g[x][i]==1&&arr[i]==0)
		{
			arr[i]=1;
			if(i==k)
				return;
			findway(i);
		}
	}
}

int main()
{
	int i,j;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(i=0;i<n;i++)
			arr[i]=0;
		k--;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&g[i][j]);
		findway(0);
		if(arr[k]==1)
			printf("Clever MM!\n");
		else
			printf("Naughty GG!\n");
	}
	return 0;
}