#include<stdio.h>
#include<string.h>

char str[101];
int main()
{
	int l;
	while(1)
	{
		gets(str);
		if(str[3]=='O')
			break;
		gets(str);
		for(l=strlen(str)-1;l>=0;l--)
		{
			if(str[l]<'A'||str[l]>'Z')
				continue;
			str[l]-=5;
			if(str[l]<'A')
				str[l]+=26;
		}
		printf("%s\n",str);
		gets(str);
		if(str[3]=='O')
			break;
	}
	return 0;
}