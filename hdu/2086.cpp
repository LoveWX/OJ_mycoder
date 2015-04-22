#include<stdio.h>

int main()
{
	int n,i;
	double ans,t;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%lf",&ans);
		scanf("%lf",&t);
		ans=n*ans+t;
		for(i=n+n;i>0;i-=2)
		{
			scanf("%lf",&t);
			ans-=i*t;
		}
		printf("%.2lf\n",ans/(n+1));
	}
	return 0;
}