#include<stdio.h>
#include<string.h>

long a[1000001],b[10001];
long next[1000001]={0,0};

int main()
{
	int time;
	long i,j;
	scanf("%d",&time);
	while(time>0)
	{
		scanf("%ld%ld",&a[0],&b[0]);
		for(i=1;i<=a[0];i++)
			scanf("%ld",&a[i]);
		for(i=1;i<=b[0];i++)
			scanf("%ld",&b[i]);
		i=1;
		j=0;
		while(i<b[0])
		{
			if(j==0||b[i]==b[j])
			{
				i++;
				j++;
				if(b[i]!=b[j])
					next[i]=j;
				else
					next[i]=next[j];
			}
			else
				j=next[j];
		}
		i=1;
		j=1;
		while(i<=a[0]&&j<=b[0])
		{
			if(j==0||a[i]==b[j])
			{
				i++;
				j++;
			}
			else
				j=next[j];
		}
		if(j>b[0])
			i=i-b[0];
		else
			i=-1;
		printf("%ld\n",i);
		time--;
	}
	return 0;
}