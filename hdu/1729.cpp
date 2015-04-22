#include<stdio.h>
#include<math.h>

long getg(long s,long n)
{
	long ss=(long)ceil((sqrt(4*s+1)-1)*0.5)-1;
	while(n<=ss)
	{
		if(n==ss)
			return 0;
		s=ss;
		ss=(long)ceil((sqrt(4*s+1)-1)*0.5)-1;
	}
	return s-n;
}

int main()
{
	int n,d=1;
	long s,c,sum;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		sum=0;
		while(n-->0)
		{
			scanf("%ld%ld",&s,&c);
			if(c==0||s==c)
				continue;
			sum^=getg(s,c);
		}
		if(sum>0)
			printf("Case %d:\nYes\n",d++);
		else
			printf("Case %d:\nNo\n",d++);
	}
	return 0;
}