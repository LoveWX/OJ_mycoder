#include<stdio.h>

void mp(long int b,long int d,long int n,long int *bb,long int *dd)
{
	long int xb,xd;
	if(n==1)
	{
		*bb=1;
		*dd=0;
		return;
	}
	if(n==2)
	{
		*bb=1;
		*dd=1;
		return;
	}
	if(n%2==0)
	{
		mp(b,d,n/2,&xb,&xd);
		*bb=(xb*(xb+2*xd))%10000;
		*dd=(xb*xb+xd*xd)%10000;
	}
	else
	{
		mp(b,d,n-1,&xb,&xd);
		*bb=((b+d)*xb+b*xd)%10000;
		*dd=(b*xb+d*xd)%10000;
	}
}

int main()
{
	long int n,b,d,t,i;
	while(1)
	{
		scanf("%ld",&n);
		if(n==-1)
			break;
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		if(n<17)
			for(b=1,d=1,i=3;i<=n;i++)
			{
				t=b+d;
				b=d;
				d=t;
			}
		else
		{
			mp(1,0,n-2,&b,&d);
			d=(b+b+d)%10000;
		}
		printf("%ld\n",d);
	}
	return 0;
}