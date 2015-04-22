#include<stdio.h>
#include<math.h>

int main()
{
	double m;
	long n;
    while(scanf("%d",&n)!=EOF)
    {
		m=n*log(n)/log(10);
		m=pow(10.0,m-floor(m));
		printf("%d\n",(int)m);
	}
	return 0;
}