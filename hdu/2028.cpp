#include<stdio.h>

__int64 getgcd(__int64 a,__int64 b)
{
	__int64 t;
	while(t=a%b)
	{
		a=b;
		b=t;
	}
	return b;
}

int  main()
{
	__int64 gcd,a[100];
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%I64d",&gcd);
			printf("%I64d\n",gcd);
			continue;
		}
		scanf("%I64d",&a[0]);
		scanf("%I64d",&a[1]);
		gcd=a[0]*a[1]/getgcd(a[0],a[1]);
		for(i=2;i<n;i++)
		{
			scanf("%I64d",&a[i]);
			gcd=a[i]*gcd/getgcd(a[i],gcd);
		}
		printf("%I64d\n",gcd);
	}
	return 0;
}