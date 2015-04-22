#include<stdio.h>
#include<math.h>

int main()
{
	int n,m;
	double sum,now;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		sum=n;
		now=n;
		m--;
		while(m-->0)
		{
			now=sqrt(now);
			sum+=now;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}