#include<stdio.h>

long int k;

long int addou(int n)
{
	int i;
	long int num=1;
	n=n/2-1;
	for(i=0;i<n;i++)
		num*=10;
	num*=9;
	return num;
}

long int addji(int n)
{
	int i;
	long int num=1;
	n=(n-1)/2-1;
	for(i=0;i<n;i++)
		num*=10;
	num*=90;
	return num;
}

void main()
{
	int n,t,i;
	long int c,num;
	while(scanf("%d",&t)!=EOF)
	{
		for(;t>0;t--)
		{
			n=2;
			scanf("%ld",&k);
			if(k<10)
			{
				printf("%ld\n",k);
				continue;
			}
			k-=9;
			while(1)
			{
				c=addou(n);
				if(k>c)
				{
					k-=c;
					n++;
				}
				else
					break;
				c=addji(n);
				if(k>c)
				{
					k-=c;
					n++;
				}
				else
					break;
			}
			if(n%2==0)
			{
				num=1;
				c=n/2-1;
				for(i=0;i<c;i++)
					num*=10;
				if(num>1)
					k=k+num-1;
				printf("%ld",k);
				while(k>0)
				{
					printf("%d",k%10);
					k/=10;
				}
				printf("\n");
			}
			else
			{
				k--;
				c=(n-1)/2-1;
				num=1;
				for(i=0;i<c;i++)
					num*=10;
				c=k/10;
				n=k%10;
				c+=num;
				printf("%ld%d",c,n);
				while(c>0)
				{
					printf("%d",c%10);
					c/=10;
				}
				printf("\n");
			}
		}
	}
}