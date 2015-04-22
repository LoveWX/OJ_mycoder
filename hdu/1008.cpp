#include<stdio.h>

int main()
{
	int n,sum,stop,now;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		sum=n*5;
		stop=0;
		while(n>0)
		{
			scanf("%d",&now);
			if(now>stop)
				sum+=(now-stop)*6;
			else if(now<stop)
				sum+=(stop-now)*4;
			stop=now;
			n--;
		}
		printf("%d\n",sum);
	}
	return 0;
}