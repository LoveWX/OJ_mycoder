#include<stdio.h>
char num[17]="0123456789ABCDEF";

int main()
{
	char s[100];
	int n,r,t;
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		t=0;
		if(n<0)
		{
			printf("-");
			n=-n;
		}
		while(n>0)
		{
			s[t++]=num[n%r];
			n/=r;
		}
		for(t--;t>=0;t--)
			printf("%c",s[t]);
		printf("\n");
	}
	return 0;
}