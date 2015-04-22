#include<stdio.h>

int g[50][50];
int arr[50];
int n;

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
			findway(i);
		}
	}
}

int main()
{
	int i,j,flag;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&g[i][j]);
			arr[i]=0;
		}
		findway(0);
		flag=1;
		for(i=0;i<n;i++)
			if(arr[i]==0)
			{
				flag=0;
				break;
			}
		if(flag==0)
		{
			printf("no\n");
			continue;
		}
		flag=0;
		for(i=0;i<n;i++)
		{
			for(j=1;j<n;j++)
				g[i][0]+=g[i][j];
			flag=flag+g[i][0]%2;
		}
		if(flag==0||flag==2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}