#include<stdio.h>
#include<string.h>
char num[1000004];
int main()
{
	long sum,i;
	while(gets(num))
	{
		sum=0;
		for(i=strlen(num);i>=0;i--)
			sum+=num[i]-'0';
		if(sum%3!=0)
			printf("MaoLaoDa will win.\n");
		else
			printf("XiaoLanXiong will win.\n");
	}
	return 0;
}