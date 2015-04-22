#include<stdio.h>

int set[2001];
int visit[2001];
int s[2001];

int findr(int r)
{
	while(set[r]!=r)
		r=set[r];
	return r;
}

int height(int x)
{
	int h=1;
	while(set[x]!=x)
	{
		h++;
		x=set[x];
	}
	return h;
}

int merge(int a,int b)
{
	int top;
	if(a==b)
		return 1;
	if(visit[a]==0&&visit[b]==0)
	{
		if(a<b)
			set[b]=a;
		else
			set[a]=b;
		visit[a]=1;
		visit[b]=1;
		return 1;
	}
	if(visit[a]>0&&visit[b]==0)
	{
		set[b]=a;
		visit[b]=1;
		return 1;
	}
	if(visit[b]>0&&visit[a]==0)
	{
		set[a]=b;
		visit[a]=1;
		return 1;
	}
	int ha=height(a)%2,hb=height(b)%2,ra=findr(a),rb=findr(b);
	if(ra==rb)
	{
		if(ha==hb)
			return 0;
		else
			return 1;
	}
	if(ha==hb)
	{
		if(ra<rb)
			set[rb]=ra;
		else
			set[ra]=rb;
	}
	else
	{
		s[0]=a;
		top=1;
		while(b!=rb)
		{
			s[top++]=b;
			b=set[b];
		}
		while(top>0)
		{
			set[b]=s[--top];
			b=set[b];
		}
	}
	return 1;
}

int main()
{
	int i,j,tcase,ncase,n;
	long nq;
	scanf("%d",&ncase);
	for(tcase=1;tcase<=ncase;tcase++)
	{
		scanf("%d%ld",&n,&nq);
		for(i=1;i<=n;i++)
		{
			visit[i]=0;
			set[i]=i;
		}
		while(nq-->0)
		{
			scanf("%d%d",&i,&j);
			if(merge(i,j)==0)
			{	
				printf("Scenario #%d:\nSuspicious bugs found!\n\n",tcase);
				while(nq-->0)
					scanf("%d%d",&i,&j);
				i=-1;
				break;
			}
		}
		if(i==-1)
			continue;
		printf("Scenario #%d:\nNo suspicious bugs found!\n\n",tcase);
	}
	return 0;
}