#include<stdio.h>

long int a[1000];

int main()
{
	int n,i,t;
	long int m,sum;
	while (1)
	{	
		scanf("%ld %d",&m,&n);
		if(n==0&&m==0)
			break;
		sum=0;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		for(i=0;i<n;i++)
		{
			scanf("%ld",&t);
			if(t==0)
				sum+=a[i];
			else
				sum+=m-a[i];
		}
		printf("%ld\n",sum);
	}
	return 0;
}