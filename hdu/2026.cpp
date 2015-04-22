#include<stdio.h>
#include<string.h>

int main()
{
	char str[1000];
	int first,len,i;
	while(gets(str))
	{
		first=1;
		len=strlen(str);
		for(i=0;i<len;i++)
			if(str[i]==' ')
				first=1;
			else if(first==1&&str[i]!=' ')
			{
				if(str[i]>='a'&&str[i]<='z')
					str[i]=str[i]-'a'+'A';
				first=0;
			}
		printf("%s\n",str);
	}
	return 0;
}