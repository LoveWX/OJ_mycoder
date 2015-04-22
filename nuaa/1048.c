#include<stdio.h>

int countv(int a,int b,int a1,int b1)
{
	a-=a1;
	b-=b1;
	if(a<0)
		a=-a;
	if(b<0)
		b=-b;
	while(b>0)
	{
		a1=a%b;
		a=b;
		b=a1;
	}
	return a-1;
}

int main()
{
	double s;
	int x1,x2,x3,y1,y2,y3,nv;
	while(1)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		if(x1==0&&y1==0&&x2==0&&y2==0&&x3==0&&y3==0)
			break;
		nv=countv(x1,y1,x2,y2)+countv(x1,y1,x3,y3)+countv(x2,y2,x3,y3)+3;
		s=((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2.0;
		if(s<0)
			s=-s;
		x1=s+1-nv/2;
		printf("%d\n",x1);
	}
	return 0;
}
//整点线段上(0,0)-(x,y)包括端点的整点个数为gcd(x,y)+1.
//Pick公式:整点多边形的面积=内部整点个数+边上的整点个数/2-1.
