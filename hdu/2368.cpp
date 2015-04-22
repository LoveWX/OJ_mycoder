#include<stdio.h>

int main()
{
	long r,a,b,ncase=1;
	while(1)
	{
		scanf("%ld",&r);
		if(r==0)
			break;
		scanf("%ld%ld",&a,&b);
		r+=r;
		r*=r;
		a=a*a+b*b;
		if(a<=r)
			printf("Pizza %d fits on the table.\n",ncase++);
		else
			printf("Pizza %d does not fit on the table.\n",ncase++);
	}
	return 0;
}