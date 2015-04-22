#include<stdio.h>

int main()
{
	int a,b,c,d,t;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		c=a;
		d=b;
		while(t=a%b)
		{
			a=b;
			b=t;
		}
		printf("%d\n",c/b*d);
	}
	return 0;
}