#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long a[1000];
	int m,n,i;
	while(scanf("%d",&m)!=EOF)
	{
		while(m>0)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
				scanf("%ld",&a[i]);
			sort(a,&a[n]);
			printf("%ld",a[0]);
			for(i=1;i<n;i++)
				printf(" %ld",a[i]);
			printf("\n");
			m--;
		}
	}
	return 0;
}