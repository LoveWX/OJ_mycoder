#include<stdio.h>
#include<string.h>

int len;
char num1[100];
char *num;
int d[10]={6,6,2,6,4,4,4,8,4,6};
int s1_10[10]={1,1,2,6,4,2,2,4,2,8};

int check()
{
	if(len<=1)
		return s1_10[num[0]-'0'];
	int t=d[num[len-1]-'0'];
	int carry=(num[len-1]+num[len-1]-'0'-'0')/10;
	int i;
	for(i=len-2;i>=0;i--)
	{
		carry=num[i]+num[i]-'0'-'0'+carry;
		num[i+1]=carry%10+'0';
		carry/=10;
	}
	if(carry==1)
		num[0]='1';
	else
	{
		len--;
		num=num+1;
	}
	if(len==1)
		i=num[0]-'0';
	else
		i=(num[len-2]-'0')*10+num[len-1]-'0';
	i%=4;

	while(i-->0)
	{
		t/=2;
		if(t&1)
			t+=5;
	}


	t*=check();
	carry=t%10;
	while(carry==0)
	{
		t/=10;
		carry=t%10;
	}
	return carry;
}

int main()
{
	while(scanf("%s",num1)!=EOF)
	{
		len=strlen(num1);
		if(len<=1)
		{
			printf("%d\n",s1_10[num1[0]-'0']);
			continue;
		}
		num=num1;
		printf("%d\n",check());
	}
	return 0;
}