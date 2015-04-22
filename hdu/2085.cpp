#include<stdio.h>

int main()
{
	int n;
	__int64 high[34],low[34];
	high[0]=1;
	low[0]=0;
	for(n=1;n<=33;n++)
	{
		low[n]=low[n-1]+high[n-1];
		high[n]=high[n-1]+high[n-1]+high[n-1]+low[n-1]+low[n-1];
	}
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		printf("%I64d, %I64d\n",high[n],low[n]);
	}
	return 0;
}