#include<stdio.h>
#define pi 3.1415927

int main()
{
	double r;
	while(scanf("%lf",&r)!=EOF)
		printf("%.3lf\n",r/3*r*r*4*pi);
	return 0;
}