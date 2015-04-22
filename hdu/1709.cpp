#include<stdio.h>
#define M 10001
int main()
{
	int i,j,n,w,sum;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&w);
			printf("%d\n",w-1);
			if(w==1)
				continue;
			printf("1");
			for(i=2;i<w;i++)
				printf(" %d",i);
			printf("\n");
			continue;
		}
		int c1[M+1]={0},c2[M+1]={0};
		scanf("%d",&sum);
		c1[0]=1;
		c1[sum]=1;
		for(i=1;i<n;i++)
		{
			scanf("%d",&w);
			sum+=w;
			for(j=0;j<=sum;j++)
				if(c1[j]!=0)
				{
					c2[j]=c1[j];
					if(j+w<=sum)
						c2[j+w]+=c1[j];
				}
			for(j=1;j<=sum;j++)
			{
				if(c1[j]!=0)
				{
					if(j-w>0)
						c2[j-w]+=c1[j];
					if(w-j>0)
						c2[w-j]+=c1[j];
				}
			}
			for(j=0;j<=sum;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		j=0;
		for(i=1;i<sum;i++)
			if(c1[i]==0)
				c2[j++]=i;
		printf("%d\n",j);
		if(j==0)
			continue;
		printf("%d",c2[0]);
		for(i=1;i<j;i++)
			printf(" %d",c2[i]);
		printf("\n");
	}
	return 0;
}