#include<stdio.h>

int main()
{
	int i;
	__int64 b[1001]={0,2,4,8};
	for(i=4;i<=1000;i++)
		b[i]=b[i-1]+i*(i-1)/2+1;
	while(scanf("%d",&i)!=EOF)
		printf("%I64d\n",b[i]);
	return 0;
}