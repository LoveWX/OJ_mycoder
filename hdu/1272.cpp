#include<stdio.h>
#define M 100001
long set[M];
long visit[M];

int findr(int x)
{
	int r=x;
	while(set[r]!=r)
		r=set[r];
	return r;
}

int merge(int a,int b)
{
	if(a==b)
		return 1;
	int ra=findr(a),rb=findr(b);
	if(ra==rb)
		return 0;
	set[ra]=rb;
	return 1;
}

int main()
{
	long i,j,r;
	for(i=1;i<M;i++)
	{
		visit[i]=0;
		set[i]=i;
	}
	while(scanf("%d%d",&i,&j)!=EOF)
	{
		if(i==-1)
			break;
		if(i==0&&j==0)
		{
			for(i=1;i<M&&visit[i]==0;i++);
			if(i==M)
			{
				printf("Yes\n");
				continue;
			}
			r=findr(i);
			for(i++;i<M;i++)
				if(visit[i]==1&&findr(i)!=r)
				{
					printf("No\n");
					r=-1;
					break;
				}
			if(r>0)
				printf("Yes\n");
			for(i=1;i<M;i++)
			{
				visit[i]=0;
				set[i]=i;
			}
			continue;
		}
		visit[i]=1;
		visit[j]=1;
		if(merge(i,j)==0)
		{
			printf("No\n");
			for(i=1;i<M;i++)
			{
				visit[i]=0;
				set[i]=i;
			}
			scanf("%d%d",&i,&j);
			while(i>0)
				scanf("%d%d",&i,&j);
			continue;	
		}
	}
	return 0;
}