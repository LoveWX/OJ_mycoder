#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	char str[1001],name[1001];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		gets(str);
		while(n>0)
		{
			gets(name);
			if(strstr(str,name)!=NULL)
				printf("yes\n");
			else
				printf("no\n");
			n--;
		}
	}
	return 0;
}