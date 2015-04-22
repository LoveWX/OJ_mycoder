#include<stdio.h>

int score[50][5];
double sum[50];

int main()
{
	int i,j,n,m,ans,flag;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			sum[i]=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&score[i][j]);
				sum[i]+=score[i][j];
			}
		}
		printf("%.2lf",sum[0]/(double)m);
		for(i=1;i<n;i++)
			printf(" %.2lf",sum[i]/(double)m);
		for(i=0;i<m;i++)
		{
			sum[i]=0;
			for(j=0;j<n;j++)
				sum[i]+=score[j][i];
		}
		sum[0]/=(double)n;
		printf("\n%.2lf",sum[0]);
		for(i=1;i<m;i++)
		{
			sum[i]/=(double)n;
			printf(" %.2lf",sum[i]);
		}
		for(i=0;i<n;i++)
		{
			flag=1;
			for(j=0;j<m;j++)
				if(score[i][j]<sum[j])
				{
					flag=0;
					break;
				}
			ans+=flag;
		}
		printf("\n%d\n\n",ans);
	}
	return 0;
}

