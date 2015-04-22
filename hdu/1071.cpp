#include<stdio.h>

int main()
{
	int n;
	double a,b,c,x1,x2,x3,y1,y2,y3;
	while(scanf("%d",&n)!=EOF)
	{
		while(n>0)
		{
			n--;
			scanf("%lf%lf",&x1,&y1);
			scanf("%lf%lf",&x2,&y2);
			scanf("%lf%lf",&x3,&y3);
			if(x1==x2&&x1==x3)
			{
				printf("0.00\n");
				continue;
			}
			if(x2>x3)
			{
				a=x2;
				x2=x3;
				x3=a;
				a=y2;
				y2=y3;
				y3=a;
			}
			if(x1==x2)
				a=(y3-y1)/((x3-x1)*(x3-x1));
			else
				a=(y2-y1)/((x2-x1)*(x2-x1));
			c=a*x1*x1+y1;
			b=-2*a*x1;
			a=((x3*a*0.33333333333+b*0.5)*x3+c)*x3-((x2*a*0.33333333333+b*0.5)*x2+c)*x2;
			b=(y2+y3)*(x3-x2)*0.5;
			if(a>b)
				a-=b;
			else
				a=b-a;
			printf("%.2lf\n",a);
		}
	}
	return 0;
}