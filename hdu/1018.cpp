#include<stdio.h>
#include<math.h>
#define PI 3.1415926536

int main()
{
	int n;
	double num;
	while(scanf("%d",&n)!=EOF)
	{
		while(n>0)
		{
			scanf("%lf",&num);
			num=ceil((num*log(num)-num+log(2*num*PI)*0.5)/log(10));
			printf("%.0lf\n",num);
			n--;
		}
	}
	return 0;
}
//string��ʽ:lnN!=NlnN-N+0.5*ln(2*N*pi)
//n!��λ��:ceil[lnN!/ln(10)],ceil()Ϊ�컨�庯��