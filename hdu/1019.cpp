#include<stdio.h>

int lcm(long x,long y)
{
	long t,a=x,b=y;
	while(b>0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return x/a*y;
}

int main()
{
	long m,n,a,b;
	scanf("%ld",&m);
	while(m>0)
	{
		m--;
		scanf("%ld",&n);
		if(n<=1)
		{
			scanf("%ld",&a);
			printf("%ld\n",a);
			continue;
		}
		scanf("%ld%ld",&a,&b);
		a=lcm(a,b);
		while(n>2)
		{
			scanf("%ld",&b);
			a=lcm(a,b);
			n--;
		}
		printf("%ld\n",a);
	}
	return 0;
}