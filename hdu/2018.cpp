#include<stdio.h>

int main()
{
	long a[55]={0,1},f[55]={0,1};
	long f1=0,f2=0,f3=0;
	int n;
	for(n=2;n<55;n++)
	{
		f[n]=f[n-1]+f3;
		f3=f2;
		f2=f1;
		f1=f[n];
		a[n]=f[n]+f1+f2+f3;
	}
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		printf("%ld\n",a[n]);
	}
	return 0;
}