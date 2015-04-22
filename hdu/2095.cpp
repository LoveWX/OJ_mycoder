#include<stdio.h>

int main()
{
	long a,b,n;
    while(1)
    {
		scanf("%ld",&n);
		if(n==0)
			break;
		b=0;
		while(n-->0)
		{
			scanf("%ld",&a);
			b^=a;
		}
		printf("%ld\n",b);
	}
    return 0;
}