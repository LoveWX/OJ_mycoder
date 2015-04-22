#include<stdio.h>
#include<math.h>

int main()
{
	double dt;
	int n,m;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
			break;
		dt=n*n-4*m;
		if(dt<0)
		{
			printf("No\n");
			continue;
		}
		dt=sqrt(dt);
		m=(int)dt;
		if(dt!=m)
		{
			printf("No\n");
			continue;
		}
		if((m+n)%2!=0)
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
	return 0;
}