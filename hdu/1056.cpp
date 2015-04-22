#include<stdio.h>

int main()
{
	double sum,current;
	int tc;
	while(1)
	{
		scanf("%lf",&sum);
		if(sum==0.00)
			break;
		current=0.5;
		tc=3;
		while(sum>0)
		{
			sum-=current;
			current=1.0/tc;
			tc++;
		}
		printf("%d card(s)\n",tc-3);
	}
	return 0;
}