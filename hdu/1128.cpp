#include<stdio.h>
bool sn[1000001];
int main()
{
	long i,m,n;
	for(i=1;i<=1000000;i++)
	{
		m=i;
		n=i;
		while(n>0)
		{
			m+=n%10;
			n/=10;
		}
		sn[m]=1;
		if(sn[i]==0)
			printf("%ld\n",i);
	}
	return 0;
}