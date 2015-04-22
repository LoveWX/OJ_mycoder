#include<stdio.h>
#include<math.h>

int main()
{
	long int i,sum,a;
	while(scanf("%ld",&i)!=EOF)
	{
		if(i==1)
		{
			printf("1\n");
			continue;
		}
		sum=i+1;
		a=(long int)(sqrt(i));
		if(a*a==i)
		{
			sum+=a;
			a--;
		}
		for(;a>=2;a--)
			if(i%a==0)
				sum=sum+a+i/a;
		printf("%ld\n",sum);	
	}
	return 0;
}