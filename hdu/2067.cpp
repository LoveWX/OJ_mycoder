#include<stdio.h>

int main()
{
	int i,n=1;
	__int64 a[36]={0,1};
	for(i=2;i<=33;i++)
		a[i]=(4*i-2)*a[i-1]/(i+1);
	a[34]=812944042149730764;
	a[35]=3116285494907301262;
	for(i=1;i<=35;i++)
		a[i]+=a[i];
	while(1)
	{
		scanf("%d",&i);
		if(i==-1)
			break;
		printf("%d %d %I64d\n",n++,i,a[i]);
	}
	return 0;
}