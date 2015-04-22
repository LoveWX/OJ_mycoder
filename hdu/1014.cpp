#include<stdio.h>

int gcd(long a,long b)
{
	long t;
	while(b>0)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main()
{
	long step,mod;
	while(scanf("%ld%ld",&step,&mod)!=EOF)
		if(gcd(step,mod)==1)
			printf("%10ld%10ld    Good Choice\n\n",step,mod);
		else
			printf("%10ld%10ld    Bad Choice\n\n",step,mod);
	return 0;
}