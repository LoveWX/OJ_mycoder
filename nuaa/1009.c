#include<stdio.h>
#include<string.h>

char str[82];
char str1[82];
char str2[82];

int main()
{
	int len,i,t;
	while(scanf("%s",str)!=EOF)
	{
		memset(str1,'0',sizeof(str1));
		memset(str2,'0',sizeof(str2));

		len=strlen(str);
		for(i=0;str[i]=='0';i++);
		str1[0]=len-i;
		for(t=len-i;i<len;)
			str1[t--]=str[i++];

		scanf("%s",str);
		len=strlen(str);
		for(i=0;str[i]=='0';i++);
		str2[0]=len-i;
		for(t=len-i;i<len;)
			str2[t--]=str[i++];

		if(len<str1[0])
			len=str1[0];
		for(i=1;i<len;i++)
		{
			str1[i]=str1[i]+str2[i]-'0';
			if(str1[i]>'9')
			{
				str1[i+1]++;
				str1[i]=str1[i]-10;
			}
		}
		str1[i]=str1[i]+str2[i]-'0';
		if(str1[i]>'9')
		{
			str1[i+1]++;
			str1[i]=str1[i]-10;
			len++;
		}

		for(i=len;i>0;i--)
			printf("%c",str1[i]);
		printf("\n");
	}
	return 0;
}