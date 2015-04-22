#include<stdio.h>
int f[23]={0,1,2};
int main()
{
	int n,i,j,sum,t;
	for(i=3;i<=22;i++)
		f[i]=f[i-1]+f[i-2];
	while(scanf("%d",&n)!=EOF)
	{
		while(n>0)
		{
			scanf("%d",&j);
			t=0;
			sum=0;
			for(i=22;j<f[i];i--);
			while(j>0)
			{
				if(j>=f[i])
				{
					sum+=f[i-1];
					j-=f[i];
				}
				i--;
			}
			printf("%d\n",sum);
			n--;
		}
	}
	return 0;
}