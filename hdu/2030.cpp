#include<stdio.h>
#include<string.h>

int main()
{
	char str[10000];
	int sum,len,i,n;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n-->0)
		{
			gets(str);
			sum=0;
			len=strlen(str);
			for(i=0;i<len;i++)
				if(str[i]<0)
					sum++;
			printf("%d\n",sum/2);
		}
	}
	return 0;
}