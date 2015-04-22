#include<stdio.h>

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		a%=10;
		if(a==0||a==1||a==5||a==6)
		{
			printf("%d\n",a);
			continue;
		}
		if(a==4)
		{
			if(b%2==1)
				printf("4\n");
			else
				printf("6\n");
			continue;
		}
		if(a==9)
		{
			if(b%2==1)
				printf("9\n");
			else
				printf("1\n");
			continue;
		}
		if(a==2)
		{
			b%=4;
			if(b==1)
				printf("2\n");
			else if(b==2)
				printf("4\n");
			else if(b==3)
				printf("8\n");
			else
				printf("6\n");
			continue;
		}
		if(a==3)
		{
			b%=4;
			if(b==1)
				printf("3\n");
			else if(b==2)
				printf("9\n");
			else if(b==3)
				printf("7\n");
			else
				printf("1\n");
			continue;
		}
		if(a==7)
		{
			b%=4;
			if(b==1)
				printf("7\n");
			else if(b==2)
				printf("9\n");
			else if(b==3)
				printf("3\n");
			else
				printf("1\n");
			continue;
		}
		if(a==8)
		{
			b%=4;
			if(b==1)
				printf("8\n");
			else if(b==2)
				printf("4\n");
			else if(b==3)
				printf("2\n");
			else
				printf("6\n");
			continue;
		}
	}
	return 0;
}