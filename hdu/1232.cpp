#include<stdio.h>

int set[1001];

int findr(int x)
{
	int r=x;
	while(set[r]!=r)
		r=set[r];
	return r;
}

void merge(int a,int b)
{
	a=findr(a);
	b=findr(b);
	if(a!=b)
		set[a]=b;
}

int main()
{
	int i,j,n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			set[i]=i;
		while(m-->0)
		{
			scanf("%d%d",&i,&j);
			merge(i,j);
		}
		m=0;
		for(i=1;i<=n;i++)
			if(set[i]==i)
				m++;
		printf("%d\n",m-1);
	}
	return 0;
}