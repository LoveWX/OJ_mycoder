#include<stdio.h>

int dp[10000];

//f[1]=dp[1];
//f[x]=f[x-1]>0?f[x-1]+a[x]:a[x];
//use current to storage value f.

int main()
{
	int i,start,end,max,last,n,current,from;
	while (1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&dp[i]);
		}
		start=0;
		end=0;
		max=dp[0];
		from=0;
		last=dp[0];
		for(i=1;i<n;i++)
		{
			current=dp[i];
			if(last>=0)
			{
				current=last+dp[i];	
			}
			else
			{
				current=dp[i];
				from=i;
			}	
			if(current>max)
			{
				max=current;
				start=from;
				end=i;
			}
			last=current;
		}
		if(max<0)
		{
			printf("0 %d %d\n",dp[0],dp[n-1]);
		}
		else
		{
			printf("%d %d %d\n",max,dp[start],dp[end]);
		}
	}
	return 0;
}
