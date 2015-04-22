#include<stdio.h>
#include<string.h>

char str[1002];

void change(int i,int j)
{
	while(i<j)
	{
		char tch=str[i];
		str[i++]=str[j];
		str[j--]=tch;
	}
}

int main()
{
	int len,n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n-->0)
		{
			gets(str);
			len=strlen(str);
			for(i=0,j=0;j<len;j++)
				if(str[j]==' ')
				{
					change(i,j-1);
					for(j++;j<len&&str[j]==' ';j++);
					i=j;
				}
			if(i!=len-1)
				change(i,len-1);
			printf("%s\n",str);
		}
	}
	return 0;
}