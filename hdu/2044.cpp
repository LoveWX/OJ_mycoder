#include<stdio.h>

int main()
{
	int a,b,n;
	__int64 ans[50]={0,1,1,2};
	for(a=4;a<50;a++)
		ans[a]=ans[a-1]+ans[a-2];
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			scanf("%d%d",&a,&b);
			printf("%I64d\n",ans[b-a+1]);
		}
	}
	return 0;
}