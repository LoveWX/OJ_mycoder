#include<stdio.h>

int main()
{
	float sum,t;
	int i;
	while(scanf("%f",&sum)!=EOF)
	{
		for(i=0;i<11;i++)
		{
			scanf("%f",&t);
			sum+=t;
		}
		printf("$%.2f\n",sum/12);
	}
	return 0;
}