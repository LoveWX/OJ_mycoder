#include<stdio.h>

int main()
{
	int g[10001];
	int f,k,a,i,l;
	while(scanf("%d%d",&f,&k)!=EOF)
	{
		for(i=1;i<=f;i++)
			g[i]=0;
		a=f;
		while(k>0)
		{
			scanf("%d%d",&l,&i);
			for(;l<=f;l+=i)
				if(g[l]==0)
				{
					g[l]=1;
					a--;
				}
			k--;
		}
		printf("%d\n",a);
	}
	return 0;
}