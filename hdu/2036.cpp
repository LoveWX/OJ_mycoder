#include<stdio.h>
#include<math.h>

struct Point 
{
	int x,y;
};

Point point[101];

int main()
{
	int i,n;
	double ans;
	while(1)
	{
		scanf("%d",&n);	
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%d%d",&point[i].x,&point[i].y);
		point[n].x=point[0].x;
		point[n].y=point[0].y;
		ans=0.0;
		for(i=1;i<=n;i++)
		{
			ans+=(point[i-1].x*point[i].y-point[i-1].y*point[i].x);
		}
		printf("%.1lf\n",ans*0.5);
	}
	return 0;
}
