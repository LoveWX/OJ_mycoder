#include<stdio.h>

int main()
{
	int a,b,i;
	char tb[80];
	char lr[80];
	tb[0]='+';
	lr[0]='|';
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		for(i=1;i<=a;i++)
		{
			tb[i]='-';
			lr[i]=' ';
		}
		tb[i]='+';
		lr[i++]='|';
		tb[i]='\0';
		lr[i]='\0';
		printf("%s\n",tb);
		while(b-->0)
			printf("%s\n",lr);
		printf("%s\n\n",tb);
	}
	return 0;
}