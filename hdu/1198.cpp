#include<stdio.h>

int up[11]={1,1,0,0,1,0,1,1,0,1,1};
int down[11]={0,0,1,1,1,0,0,1,1,1,1};
int left[11]={1,0,1,0,0,1,1,1,1,0,1};
int right[11]={0,1,0,1,0,1,1,0,1,1,1};
int set[2501];
char pipe[51][51];
int m,n;

int findr(int r)
{
	while(r!=set[r])
		r=set[r];
	return r;
}

void rmerge(int i,int j)
{
	int ra,rb;
	if(down[pipe[i][j]-'A']==1&&up[pipe[i+1][j]-'A']==1)
	{
		ra=findr((i-1)*n+j);
		rb=findr(i*n+j);
		if(ra!=rb)
			set[rb]=ra;
	}
}

void cmerge(int i,int j)
{
	int ra,rb;
	if(right[pipe[i][j]-'A']==1&&left[pipe[i][j+1]-'A']==1)
	{
		ra=findr((i-1)*n+j);
		rb=findr((i-1)*n+j+1);
		if(ra!=rb)
			set[rb]=ra;
	}
}

int main()
{
	int i,j;
	for(i=1;i<=2500;i++)
		set[i]=i;
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(m<0)
			break;
		getchar();
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%c",&pipe[i][j]);
			getchar();
		}
		for(i=1;i<m;i++)
			for(j=1;j<=n;j++)
				rmerge(i,j);
		for(i=1;i<=m;i++)
			for(j=1;j<n;j++)
				cmerge(i,j);
		j=0;
		for(i=1;i<=m*n;i++)
		{
			if(set[i]==i)
				j++;
			set[i]=i;
		}
		printf("%d\n",j);
	}
	return 0;
}