#include<stdio.h>

int n,k;
char str[12];
__int64 dp[11][7];

__int64 num(int a,int b)
{
	__int64 t=0;
	for(;a<=b;a++)
		t=t*10+str[a]-'0';
	return t;
}

int main()
{
	int i,j,t;
	__int64 max,temp;
	str[0]=' ';
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		getchar();
		gets(str+1);
		dp[n][0]=num(n,n);
		temp=10;
		for(i=n-1;i>0;i--)
		{
			dp[i][0]=dp[i+1][0]+temp*(str[i]-'0');
			temp*=10;
		}
		for(j=1;j<=k;j++)
			for(i=1;i<=n-j;i++)
			{
				max=-1;
				for(t=i;t<n;t++)
				{
					temp=num(i,t)*dp[t+1][j-1];
					if(temp>max)
						max=temp;
				}
				dp[i][j]=max;
			}
        printf("%I64d\n",dp[1][k]);
	}
	return 0;
}