#include<stdio.h>

int change(char *s)
{
	switch(s[0])
	{
	case 'z':
		return 0;
	case 'o':
		return 1;
	case 't':
		if(s[1]=='w')
			return 2;
		else
			return 3;
	case 'f':
		if(s[1]=='o')
			return 4;
		else
			return 5;
	case 's':
		if(s[1]=='i')
			return 6;
		else
			return 7;
	case 'e':
		return 8;
	case 'n':
		return 9;
	}
	return 0;
}

int main()
{
	char str[10];
	int a,b;
	while(1)
	{
		a=0;
		while(1)
		{
			scanf("%s",str);
			if(str[0]=='+')
				break;
			a=a*10+change(str);
		}
		b=0;
		while(1)
		{
			scanf("%s",str);
			if(str[0]=='=')
				break;
			b=b*10+change(str);
		}
		if(a==0&&b==0)
			break;
		printf("%d\n",a+b);
		getchar();
	}
	return 0;
}