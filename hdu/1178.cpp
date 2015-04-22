#include<stdio.h>

int main()
{
	double a;
	long n;
	char ts[10];
	while(scanf("%ld",&n)!=EOF)
	{
		if(n==0)
			break;
		a=n*0.5*(n+1)/3.0*(n+2);
		sprintf(ts,"%.2E",a);
		n=(ts[7]-'0')*10+ts[8]-'0';
		ts[5]='\0';
		printf("%s%d\n",ts,n);
	}
	return 0;
}