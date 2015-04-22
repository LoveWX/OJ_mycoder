#include<iostream>
#include<algorithm>
using namespace std;

long a[10000],b[10000];
int ta,tb,bb,n;

long getnum()
{
	if(ta>=n)
		return b[tb++];
	if(tb>=bb)
		return a[ta++];
	if(a[ta]>b[tb])
		return b[tb++];
	else
		return a[ta++];
}

int main()
{
	int i;
	long sum,t;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(&a[0],&a[n]);
		sum=0;
		ta=0;
		tb=0;
		bb=0;
		for(i=1;i<n;i++)
		{
			t=getnum()+getnum();
			b[bb++]=t;
			sum+=t;
		}
		printf("%ld\n",sum);
	}
	return 0;
}