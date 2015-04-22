#include<stdio.h>
#include<string.h>

int main()
{
	int l,sum;
	char num[2000];
	while(1)
	{
		gets(num);
		if(num[0]=='0')
			break;
		do
		{
			sum=0;
			for(l=strlen(num)-1;l>=0;l--)
				sum+=num[l]-'0';
			sprintf(num,"%d",sum);
		}while(sum>=10);
		printf("%d\n",sum);
	}
	return 0;
}