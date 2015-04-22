#include<stdio.h>
#define MAX 15001

int num[MAX];
bool r[MAX];

int main()
{
	int i,j,k,tcase,d=1,m,n,sum;
	while(scanf("%d",&tcase)!=EOF)
	{
		while(tcase-->0)
		{
			scanf("%d%d",&m,&n);
			k=-1;
			for(i=0;i<m;i++)
			{
				scanf("%d",&num[i]);
				if(num[i]>k)
					k=num[i];
			}
			for(i=0;i<m;i++)
			{
				r[num[i]]=1;
				r[num[i]+num[i]]=1;
				if(num[i]!=k)
					r[num[i]+num[i]+num[i]]=1;
			}
			num[0]=0;
			m=1;
			sum=k+k+k;
			for(i=1;i<=sum;i++)
				if(r[i])
				{
					num[m++]=i;
					r[i]=0;
				}
			sum=num[m-1]*n;

			bool c1[MAX]={1},c2[MAX]={0};
			for(i=0;i<m;i++)
				c1[num[i]]=1;
			for(i=1;i<n;i++)
			{
				for(j=0;j<=sum;j++)
					if(c1[j])
						for(k=0;k<m;k++)
							if(j+num[k]<=sum)
								c2[j+num[k]]=1;
				for(j=0;j<=sum;j++)
				{
					c1[j]|=c2[j];
					c2[j]=0;
				}
			}
			k=0;
			for(i=0;i<=sum;i++)
				if(c1[i])
					k++;
			printf("Scenario #%d:\n%d\n\n",d++,k);
		}
	}
	return 0;
}