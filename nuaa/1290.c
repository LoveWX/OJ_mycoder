#include<stdio.h>

int n;

void printmax()
{
	int i;
	if(n%2==0)
		i=n;
	else
	{
		i=n-3;
		printf("7");
	}
	i/=2;
	while (i-->0)
		printf("1");
}

void printmin()
{
	int i,j;
	i=n%7;
	j=n/7;
	if(i==0)
	{
		while(j-->0)
			printf("8");
		return;
	}
	else if(i==1)
	{
		printf("10");
		j--;
		while (j-->0)
			printf("8");
		return;
	}
	else if(i==2)
	{
		printf("1");
		while (j-->0)
			printf("8");
		return;
	}
	else if(i==3)
	{
		if(j==0)
			printf("7");
		else if(j==1)
			printf("22");
		else
		{
			printf("200");
			j-=2;
			while (j-->0)
				printf("8");
		}
		return;
	}
	else if(i==4)
	{
		if(j==0)
		{
			printf("4");
			return;
		}
		printf("20");
		j--;
		while (j-->0)
			printf("8");
		return;
	}
	else if(i==5)
	{
		printf("2");
		while (j-->0)
			printf("8");
		return;
	}
	else if(i==6)
	{
		printf("6");
		while (j-->0)
			printf("8");
		return;
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		printmin();
		printf(" ");
		printmax();
		printf("\n");
	}
	return 0;
}