#include<stdio.h>

int tri[101][101];

void init()
{
	int i,j;
	for(i=0;i<101;i++)
		for(j=0;j<101;j++)
			tri[i][j]=0;
}

int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}

int main()
{
	int r,i,j;
	while(1)
	{
		scanf("%d",&r);
		if(r==0)
			break;
		init();
		for(i=1;i<=r;i++)
			for(j=1;j<=i;j++)
				scanf("%d",&tri[i][j]);
		for(i=2;i<=r;i++)
			for(j=1;j<=i;j++)
				tri[i][j]+=max(tri[i-1][j-1],tri[i-1][j]);
		j=tri[r][1];
		for(i=1;i<=r;i++)
			if(tri[r][i]>j)
				j=tri[r][i];
		printf("%d\n",j);
	}
	return 0;
}