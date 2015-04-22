#include<stdio.h>

int check(char c)
{
	if(c>='a'&&c<='z')
		return 1;
	if(c>='A'&&c<='Z')
		return 1;
	if(c>='0'&&c<='9')
		return 1;
	if(c=='_')
		return 1;
	return 0;
}

int main()
{
	int n,i;
	char str[100];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n-->0)
		{
			gets(str);
			if((str[0]<='9'&&str[0]>='0')||check(str[0])==0)
			{
				printf("no\n");
				continue;
			}
			for(i=1;str[i]!='\0';i++)
				if(check(str[i])==0)
				{
					printf("no\n");
					i=-1;
					break;
				}
			if(i>0)
				printf("yes\n");
		}
	}
	return 0;
}