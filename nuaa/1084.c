#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int na[5000000],nb[5000000],nc[5000000];
int r;

void findk(long int n,long int k,int *a,int *b,int *c)
{
	int ta=0,tb=0,m,i;
	if(n<=10)
	{
		n--;
		for(ta=0;ta<n;ta++)
			for(tb=0;tb<n;tb++)
				if(c[tb]>c[tb+1])
				{
					m=c[tb];
					c[tb]=c[tb+1];
					c[tb+1]=m;
				}
		r=c[k-1];
		return;
	}
	m=c[n-k];
	for(i=0;i<n;i++)
	{
		if(c[i]<=m)
			a[ta++]=c[i];
		else
			b[tb++]=c[i];
	}
	if(ta==k)
		r=m;
	else if(ta>k)
		findk(ta,k,b,c,a);
	else
		findk(tb,k-ta,a,c,b);
}

int main()
{
	int n,k,i;
	while(1)
	{
		scanf("%d%d",&n,&k);
		if(n==0&&k==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&nc[i]);
		findk(n,k,na,nb,nc);
		printf("%d\n",r);
	}
	return 0;
}