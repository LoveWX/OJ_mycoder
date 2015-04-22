#include<stdio.h>

int main()
{
	double sum,a,b;
	char kind[100];
	sum=0;
	while(scanf("%s%lf%lf",kind,&a,&b)!=EOF)
		sum+=a*b;
	printf("%.1lf\n",sum);
	return 0;
}