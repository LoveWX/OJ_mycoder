#include<stdio.h>

int main()
{
	int w,d,n;
	while (scanf("%d",&n)!=EOF)
	{
		while (n>0)
		{
			scanf("%d%d",&w,&d);
			if(w%2!=0&&d%2!=0)
				printf("no\n");
			else
				printf("yes\n");
			n--;
		}
	}
	return 0;
}