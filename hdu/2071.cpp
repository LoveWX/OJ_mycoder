#include<stdio.h>

int main()
{
	int n,m;
	double h,t;
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			scanf("%d",&m);
			m--;
			scanf("%lf",&h);
			while(m-->0)
			{
				scanf("%lf",&t);
				if(t>h)
					h=t;
			}
			printf("%.2lf\n",h);
		}
	}
	return 0;
}