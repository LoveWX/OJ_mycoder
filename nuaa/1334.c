#include<stdio.h>

int grid[53][53];

int main()
{
	int i,j,n;
	grid[1][0]=0;
	grid[2][0]=-1;
	grid[2][1]=0;
	grid[3][0]=-2;
	grid[3][1]=-1;
	grid[3][2]=0;
	for(i=4;i<=52;i++)
	{
		grid[i][0]=1-i;
		grid[i][1]=grid[i-1][i-3];
		grid[i][2]=grid[i-1][i-2];
		n=0;
		for(j=3;j<i;j++)
			grid[i][j]=grid[i-1][n++];
	}
	while (scanf("%d",&n)!=EOF)
	{
		printf("1");
		for(i=1;i<n;i++)
		{
			printf(" %d",n+grid[n][i]);
		}
		printf("\n");
	}
	return 0;
}