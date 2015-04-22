#include<stdio.h>

void mysort(long *a,long *b,long *c)
{
	long t;
	if(*a>*b)
	{
		t=*a;
		*a=*b;
		*b=t;
	}
	if(*b>*c)
	{
		t=*b;
		*b=*c;
		*c=t;
	}
	if(*a>*b)
	{
		t=*a;
		*a=*b;
		*b=t;
	}
}

int main()
{
	int d=1,tcase;
	long a,b,c;
	while(scanf("%d",&tcase)!=EOF)
	{
		while(tcase-->0)
		{
			scanf("%ld%ld%ld",&a,&b,&c);
			mysort(&a,&b,&c);
			printf("Scenario #%d:\n",d++);
			if(a*a+b*b==c*c)
				printf("yes\n\n");
			else
				printf("no\n\n");
		}
	}
	return 0;
}
