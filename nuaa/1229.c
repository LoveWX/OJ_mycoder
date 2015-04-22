#include<stdio.h>

long num[101];
long temp[101];
long temptop;

int main()
{
	int i,j,k;
	long n,a,b,c;
	while(scanf("%ld%d",&n,&k)!=EOF)
	{
		for(i=1;i<=n;i++)
			num[i]=i;
		while(k-->0)
		{
			scanf("%ld%ld%ld",&a,&b,&c);
			if(a-1==c)
				continue;
			temptop=0;
			if(c<a)//up
			{
				for(i=c+1;i<a;i++)
					temp[temptop++]=num[i];
				j=c+1;
				for(i=a;i<=b;i++,j++)
					num[j]=num[i];
				for(i=0;i<temptop;i++,j++)
					num[j]=temp[i];
			}
			else//down
			{
				for(i=a;i<=b;i++)
					temp[temptop++]=num[i];
				j=b+1;
				b=c-a+b+1;
				for(i=a;j<=b;i++,j++)
					num[i]=num[j];
				for(j=0;j<temptop;i++,j++)
					num[i]=temp[j];
			}
		}
		for(i=1;i<=10;i++)
			printf("%ld\n",num[i]);
	}
	return 0;
}