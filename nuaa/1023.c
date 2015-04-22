#include<stdio.h>
//#define M 10000001
#define M 101
bool c1[M],c2[M];

int main()
{
    int n,d=1;
	long t,sum,i;
    while(scanf("%d",&n)!=EOF)
    {
		if(n==0)
		{
			printf("Case %d: 0 0\n",d++);
			continue;
		}
		scanf("%ld",&sum);
		c1[0]=1;
		c1[sum]=1;
        while(n-->1)
        {
			scanf("%ld",&t);
            for(i=0;i<=sum;i++)
				if(c1[i])
				{
					c2[i]=1;
					c2[i+t]=1;
				}
            sum+=t;
			for(i=0;i<=sum;i++)
			{
				c1[i]=c2[i];
				c2[i]=0;
			}
        }
		for(i=sum/2;i>=0;i--)
            if(c1[i])
                break;
		printf("Case %d: %ld %ld\n",d++,i,sum-i);
		for(i=sum;i>=0;i--)
			c1[i]=0;
    }
    return 0;
}