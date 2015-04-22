#include<stdio.h>

int main()
{
	char str[12];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n-->0)
		{
			gets(str);
			printf("6%s\n",str+6);
		}
	}
	return 0;
}