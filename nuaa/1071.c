#include<stdio.h>

int judge(int n)
{
	int t10=0,t12=0,t16=0;
	int a=n;
	while(a!=0)
	{
		t10=t10+a%10;
		a=a/10;
	}
	a=n;
	while(a!=0)
	{
		t12=t12+a%12;
		a=a/12;
	}
	a=n;
	while(a!=0)
	{
		t16=t16+a%16;
		a=a/16;
	}
	if(t10==t12&&t12==t16)
		return 1;
	else
		return 0;
}

void main()
{
	int i;
	for(i=2992;i<=9999;i++)
		if(judge(i)==1)
			printf("%d\n",i);
}