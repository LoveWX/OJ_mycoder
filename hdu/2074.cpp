#include<stdio.h>
#include<string.h>

char s[80][80];

int main()
{
	int n,i,b,e,t,first=1;
	char cha,chb,str[80];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		if(n%4==1)
		{
			scanf("%c",&cha);
			getchar();
			scanf("%c",&chb);
		}
		else
		{
			scanf("%c",&chb);
			getchar();
			scanf("%c",&cha);
		}
		getchar();
		if(first!=1)
			printf("\n");
		else
			first=0;
		if(n==1)
		{
			printf("%c\n",cha);
			continue;
		}
		str[0]=' ';
		str[n]='\0';
		for(i=1;i<n;i++)
			str[i]=cha;
		str[n-1]=' ';
		printf("%s\n",str);
		strcpy(s[0],str);
		b=1;e=n-2;
		t=1;
		str[0]=cha;
		str[n-1]=cha;
		while(b<=e)
		{
			for(i=b;i<=e;i++)
				str[i]=chb;
			printf("%s\n",str);
			strcpy(s[t++],str);
			if(++b>--e)
				break;
			for(i=b;i<=e;i++)
				str[i]=cha;
			printf("%s\n",str);
			strcpy(s[t++],str);
			b++;
			e--;
		}
		for(i=b-2;i>=0;i--)
			printf("%s\n",s[i]);
	}
	return 0;
}