#include<stdio.h>

int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			scanf("%d%d",&a,&b);
			if(a%b==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}