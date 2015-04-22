#include<stdio.h>

int grid[100][100];
int temp[100][100];
int ans[100][100];
int t[100];
int n;

void mul()
{
	int i,j,k,s;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			s=0;
			for(k=0;k<n;k++)
				s+=grid[i][k]*temp[k][j];
			t[j]=s;
		}
		for(j=0;j<n;j++)
		{
			grid[i][j]=t[j];
			ans[i][j]+=t[j];
		}
	}
}

int main()
{
	int i,j,nt;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&nt);
				grid[i][j]=nt;
				temp[i][j]=nt;
				ans[i][j]=nt;
			}
		nt=n;
		while(nt>1)
		{
			mul();
			nt--;
		}
		scanf("%d",&nt);
		while(nt>0)
		{
			scanf("%d %d",&i,&j);
			if(ans[i-1][j-1]!=0)
				printf("yes\n");
			else
				printf("no\n");
			nt--;
		}
	}
	return 0;
}