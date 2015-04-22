#include<stdio.h>

long ans[30]={0,1};

int main()
{
	int n;
	for(n=2;n<30;n++)
		ans[n]=ans[n-1]+ans[n-1]+2;
	while(scanf("%d",&n)!=EOF)
		printf("%ld\n",ans[n]);
	return 0;
}