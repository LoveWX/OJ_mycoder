#include<stdio.h>

long int t[7]={9,81,729,6561,59049,531441,4782969};

int main()
{
	long int a,b;
	int l,n,i;
	int num[7],d[9];
	while(scanf("%ld%d",&a,&l)!=EOF)
	{
		if(l!=0)
		{
			for(i=0;i<l;i++)
				d[i]=i;
			for(i=l+1;i<=9;i++)
				d[i-1]=i;
			i=0;
			while(a>0)
			{
				num[i++]=d[a%9];
				a/=9;
			}
		}
		else
		{
			if(a<=9)
			{
				printf("%ld\n",a);
				continue;
			}
			i=0;
			n=0;
			b=a;
			while(a>t[n])
			{
				a-=t[n++];
			}
			while(n>=0)
			{
				if(b%9!=0)
					num[i++]=b%9;
				else
				{
					num[i++]=9;
					b-=9;
				}
				b/=9;
				n--;
			}
		}
		i--;
		while(i>=0)
		{
			printf("%d",num[i--]);
		}
		printf("\n");
	}
	return 0;
}