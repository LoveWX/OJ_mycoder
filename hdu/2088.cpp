#include<stdio.h>

int main()
{
	int n,i,sum,t,h[51],first=1;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			h[i]=t;
			sum+=t;
		}
		sum/=n;
		t=0;
		for(i=0;i<n;i++)
		{
			if(h[i]>sum)
				t+=h[i]-sum;
			else
				t+=sum-h[i];
		}
		if(first!=1)
			printf("\n");
		else
			first=0;
		printf("%d\n",t/2);
	}
	return 0;
}