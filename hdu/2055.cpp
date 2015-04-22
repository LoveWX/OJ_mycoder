#include<stdio.h>

int num[60];

int main()
{
	char ch;
	int i,n;
	for(i=0,n=1;i<26;i++,n++)
	{
		num[i]=n;
		num[i+32]=-n;
	}
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n-->0)
		{
			scanf("%c",&ch);
			getchar();
			scanf("%d",&i);
			getchar();
			i+=num[ch-'A'];
			printf("%d\n",i);
		}
	}
	return 0;
}