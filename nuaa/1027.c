#include<stdio.h>

int main()
{
	int a,c;
	while(scanf("%d %d",&a,&c)!=EOF)
	{
		printf("%d\n",2*c-a);
	}
	return 0;
}