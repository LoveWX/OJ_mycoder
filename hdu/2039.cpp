#include<stdio.h>

int main()
{
	int n;
	double a,b,c;
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			scanf("%lf%lf%lf",&a,&b,&c);
			if(a+b>c&&b+c>a&&a+c>b)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}