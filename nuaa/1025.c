#include<stdio.h>
#define MAX 100000

int f[MAX];
int visit[MAX];

int main()
{
	int i,xx,yy;
	long n,t;
	while(scanf("%ld",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&f[i]);
		scanf("%ld",&t);
		while(t>0)
		{
			scanf("%d",&xx);
			i=xx;
			while(xx!=0)
			{
				visit[xx]=1;
				xx=f[xx];
			}
			scanf("%d",&yy);
			while(yy!=0)
			{
				if(visit[yy]==1)
				{
					printf("%d\n",yy);
					break;
				}
				yy=f[yy];
			}
			xx=i;
			while(f[xx]!=0)
			{
				visit[xx]=0;
				xx=f[xx];	
			}
			t--;
		}
	}
	return 0;
}