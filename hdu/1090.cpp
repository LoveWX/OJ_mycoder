#include<stdio.h>

int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		while(n>0)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",a+b);
			n--;
		}
	}
	return 0;
}