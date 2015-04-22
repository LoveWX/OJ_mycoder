#include<stdio.h>
#include<math.h>

int main()
{
	long num,t;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(n>0)
		{
			scanf("%ld",&num);
			t=(long)(sqrt(8.0*num+1)*0.5-0.5);
			if(t*(t+1)/2==num)
				t--;
			t=((long)(num-(t+1)*0.5*t))%9;
			if(t==0)
				t=9;
			printf("%ld\n",t);
			n--;
		}
	}
	return 0;
}