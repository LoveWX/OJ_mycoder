#include<stdio.h>

int main()
{
	int n,m,temp;
	long int t1,t;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
			break;
		t=n*(n+1)*m*(m+1)/4;
		if(n<m)
		{
			temp=n;
			n=m;
			m=temp;
		}
		t1=0;
		while(m>0)
		{
			t1=t1+n*m;
			n--;
			m--;
		}
		printf("%ld %ld\n",t1,t-t1);
	}
	return 0;
}