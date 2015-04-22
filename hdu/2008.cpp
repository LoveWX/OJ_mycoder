#include<stdio.h>

int main()
{
	int n,s1,s2,s3;
	double t;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		s1=0;
		s2=0;
		s3=0;
		while(n-->0)
		{
			scanf("%lf",&t);
			if(t>0)
				s3++;
			else if(t==0)
				s2++;
			else
				s1++;
		}
		printf("%d %d %d\n",s1,s2,s3);
	}
	return 0;
}