#include<stdio.h>

int main()
{
	__int64 a,b;
	while(scanf("%I64X%I64X",&a,&b)!=EOF)
	{
		a+=b;
		if(a>=0)
			printf("%I64X\n",a);
		else
			printf("-%I64X\n",-a);
	}
	return 0;
}
