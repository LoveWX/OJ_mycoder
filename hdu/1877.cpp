#include<stdio.h>

int num[100];
int t;

int main()
{
	__int64 a,b;
	int m;
	while(1)
	{
		scanf("%d",&m);
		if(m==0)
			break;
		scanf("%I64d%I64d",&a,&b);
		a+=b;
		if(a==0)
		{
			printf("0\n");
			continue;
		}
		t=0;
		while(a>0)
		{
			num[t++]=(int)(a%(__int64)m);
			a/=m;
		}
		for(t--;t>=0;t--)
			printf("%d",num[t]);
		printf("\n");
	}
	return 0;
}