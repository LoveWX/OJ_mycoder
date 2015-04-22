#include<stdio.h>

int main()
{
	__int64 maxx,minx,maxy,miny,maxz,minz,x,y,z,r;
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		while(n-->0)
		{
			maxx=-1;
			maxy=-1;
			maxz=-1;
			minx=200001;
			miny=200001;
			minz=200001;
			for(i=0;i<8;i++)
			{
				scanf("%I64d%I64d%I64d",&x,&y,&z);
				if(x>maxx)
					maxx=x;
				if(x<minx)
					minx=x;
				if(y>maxy)
					maxy=y;
				if(y<miny)
					miny=y;
				if(z>maxz)
					maxz=z;
				if(z<minz)
					minz=z;
			}
			scanf("%I64d%I64d%I64d%I64d",&x,&y,&z,&r);
			if(x<minx)
				x=(minx-x)*(minx-x);
			else if(x>maxx)
				x=(maxx-x)*(maxx-x);
			else
				x=0;
			if(y<miny)
				y=(miny-y)*(miny-y);
			else if(y>maxy)
				y=(maxy-y)*(maxy-y);
			else
				y=0;
			if(z<minz)
				z=(minz-z)*(minz-z);
			else if(z>maxz)
				z=(maxz-z)*(maxz-z);
			else
				z=0;
			if(x+y+z<=r*r)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}