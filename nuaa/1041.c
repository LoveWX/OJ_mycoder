#include<stdio.h>

#define M 200001

long b,t;
long queue[M];
long step[M];
int pos[M];

void add(int n)
{
	int tt,st=step[b]+1;
	tt=n-1;
	if(pos[tt]==0)
	{
		queue[t]=tt;
		step[t++]=st;
		pos[tt]=1;
	}
	tt=n+1;
	if(pos[tt]==0)
	{
		queue[t]=tt;
		step[t++]=st;
		pos[tt]=1;
	}
	if(n<100000)
	{
		tt=n*2;
		if(pos[tt]==0)
		{
			queue[t]=tt;
			step[t++]=st;
			pos[tt]=1;
		}
	}
}

int main()
{
	long n,k;
	while(scanf("%ld%ld",&n,&k)!=EOF)
	{
		if(k<=n)
		{
			printf("%ld\n",n-k);
			continue;
		}
		b=0;
		t=1;
		pos[n]=1;
		queue[0]=n;
		step[0]=0;
		while(n!=k)
		{
			add(n);
			n=queue[++b];
		}
		printf("%ld\n",step[b]);
		for(n=0;n<t;n++)
			pos[queue[n]]=0;
	}
	return 0;
}