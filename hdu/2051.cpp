#include<stdio.h>

int main()
{
	int n,t;
	int stack[11];
	while(scanf("%d",&n)!=EOF)
	{
		t=0;
		while(n>0)
		{
			stack[t++]=n&1;
			n>>=1;
		}
		t--;
		while(t>=0)
			printf("%d",stack[t--]);
		printf("\n");
	}
	return 0;
}