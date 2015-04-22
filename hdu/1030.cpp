#include<stdio.h>
#include<math.h>

int main()
{
	long a1,a2,b1,b2,c1,c2,n,m;
	while(scanf("%ld%ld",&n,&m)!=EOF)
	{
		c1=(long)ceil(sqrt(n));
		a1=(n-(c1-1)*(c1-1)+1)*0.5;
		b1=(c1*c1-n)*0.5+1;
		c2=(long)ceil(sqrt(m));
		a2=(m-(c2-1)*(c2-1)+1)*0.5;
		b2=(c2*c2-m)*0.5+1;
		if(a1>a2)
			a1-=a2;
		else
			a1=a2-a1;
		if(b1>b2)
			a1+=b1-b2;
		else
			a1+=b2-b1;
		if(c1>c2)
			a1+=c1-c2;
		else
			a1+=c2-c1;
		printf("%ld\n",a1);
	}
	return 0;
}