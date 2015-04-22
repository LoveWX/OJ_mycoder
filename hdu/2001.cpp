#include<stdio.h>
#include<math.h>

int main()
{
	double x1,x2,y1,y2;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		x1-=x2;
		y1-=y2;
		printf("%.2lf\n",sqrt(x1*x1+y1*y1));
	}
	return 0;
}