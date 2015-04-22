#include<stdio.h>

int num10[9]={1,10,100,1000,10000,10000,10000,10000,10000};

int main()
{
	int a,b,k;
	while(1)
	{
		scanf("%d%d%d",&a,&b,&k);
		if(a==0&&b==0)
			break;
		if(a%num10[k]==b%num10[k])
			printf("-1\n");
		else
			printf("%d\n",a+b);
	}
	return 0;
}