#include<stdio.h>

int main()
{
	__int64 h1,h2,m1,m2,s1,s2;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&h1,&m1,&s1,&h2,&m2,&s2);
			s1+=s2;
			m1+=m2+s1/60;
			s1%=60;
			h1+=h2+m1/60;
			m1%=60;
			printf("%I64d %I64d %I64d\n",h1,m1,s1);
		}
	}
	return 0;
}