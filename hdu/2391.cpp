#include <stdio.h>

long grid[1000][1000];

inline long max(long a,long b)
{
	if(a<b)
		return b;
	return a;
}

int main()
{
	int d=1,i,j,r,c,tcase;
	while(scanf("%d",&tcase)!=EOF)
	{
		while(tcase-->0)
		{
			scanf("%d%d",&r,&c);
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					scanf("%d",&grid[i][j]);
			for(i=1;i<r;i++)
				grid[i][0]+=grid[i-1][0];
			for(i=1;i<c;i++)
				grid[0][i]+=grid[0][i-1];
			for(i=1;i<r;i++)
				for(j=1;j<c;j++)
					grid[i][j]+=max(grid[i-1][j],grid[i][j-1]);
			printf("Scenario #%d:\n%ld\n\n",d++,grid[r-1][c-1]);
		}
	}
    return 0;
}