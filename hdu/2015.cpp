#include<stdio.h>
//数学题，等差数列，别告诉我你是用模拟做的。
int main()
{
	int n,m,i,t;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		t=1+m;
		printf("%d",t);
		for(i=n/m-1,t=t+m+m;i>0;i--,t=t+m+m)
			printf(" %d",t);
		if(n%m!=0)
			printf(" %d",n+n+1-n%m);
		printf("\n");
	}
	return 0;
}
