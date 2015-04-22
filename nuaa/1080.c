#include<stdio.h>

double min(double x,double y)
{
	if(x<y)
		return x;
	return y;
}

double max(double x,double y)
{
	if(x>y)
		return x;
	return y;
}

double mulx(double a1,double b1,double a2,double b2)
{
	return a1*b2-a2*b1;
}

int main()
{
	double x1,x2,x3,x4,y1,y2,y3,y4,t1,t2;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
	{
		if(!(min(x1,x2)<=max(x3,x4)
			&&min(x3,x4)<=max(x1,x2)
			&&min(y1,y2)<=max(y3,y4)
			&&min(y3,y4)<=max(y1,y2)))
		{
			printf("no\n");
			continue;
		}
		t1=mulx(x1-x3,y1-y3,x4-x3,y4-y3)*mulx(x2-x3,y2-y3,x4-x3,y4-y3);
		t2=mulx(x3-x1,y3-y1,x2-x1,y2-y1)*mulx(x4-x1,y4-y1,x2-x1,y2-y1);
		if(t1<=0&&t2<=0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}