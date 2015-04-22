#include<stdio.h>

int main()
{
	int n;
	char oper;
	long a,b;
	double t;
	while(scanf("%d",&n)!=EOF)
	{
		while(n>0)
		{
			getchar();
			scanf("%c %ld %ld",&oper,&a,&b);
			if(oper=='+')
				printf("%ld\n",a+b);
			else if(oper=='-')
				printf("%ld\n",a-b);
			else if(oper=='*')
				printf("%ld\n",a*b);
			else if(oper=='/')
			{
				if(a%b==0)
					printf("%ld\n",a/b);
				else
				{
					t=b;
					printf("%.2lf\n",a/t);
				}
			}
			n--;
		}
	}
	return 0;
}