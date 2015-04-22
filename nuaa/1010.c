#include<stdio.h>

int main()
{
	int n,k,i,pos,num;
	int p[101];
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		pos=0;
		for(i=0;i<n;i++)
			p[i]=1;
		num=n;
		while(num>1)
		{
			i=k;
			while(1)
			{
				if(p[pos]==1)
					i--;
				if(i<=0)
					break;
				pos=(pos+1)%n;
			}
			p[pos]=0;
			num--;
		}
		for(i=0;p[i]==0;i++);
		printf("%d\n",i+1);
	}
	return 0;
}