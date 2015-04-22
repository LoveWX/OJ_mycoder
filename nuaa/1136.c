#include<stdio.h>

char code[100];
int len;

void btog(int l)
{
	for(l--;l>0;l--)
		if(code[l]==code[l-1])
			code[l]='0';
		else
			code[l]='1';
}

void gtob(int l)
{
	int i;
	for(i=1;i<l;i++)
		if(code[i]==code[i-1])
			code[i]='0';
		else
			code[i]='1';
}

int main()
{
	char b,c;
	while(1)
	{
		scanf("%s%c%c",code,&b,&c);
		if(c=='0')
			break;
		for(len=0;code[len]!='\0';len++);
		if(c=='B')
			btog(len);
		else
			gtob(len);
		printf("%s\n",code);
	}
	return 0;
}