#include<stdio.h>

int main()
{
	int i,k=2;
	double now=2.5;
	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
	for(i=3;i<=9;i++)
	{
		k*=i;
		now+=1.0/k;
		printf("%d %.9lf\n",i,now);
	}
	return 0;
}