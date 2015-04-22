#include<stdio.h>

int main()
{
	int q,n;
	long int num[45]={1,2};
	for(n=2;n<45;n++)
		num[n]=num[n-2]+num[n-1];
	while(scanf("%d",&q)!=EOF)
	{
		while(q>0)
		{
			scanf("%d",&n);
			printf("%ld\n",num[n]);
			q--;
		}
	}
	return 0;
}