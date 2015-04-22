#include<stdio.h>
#define M 1001
double x1[M],x2[M],y1[M],y2[M];
int set[M];

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

int iscross(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
	double t1,t2;
    if(!(min(x1,x2)<=max(x3,x4)
		&&min(x3,x4)<=max(x1,x2)
		&&min(y1,y2)<=max(y3,y4)
		&&min(y3,y4)<=max(y1,y2)))
			return 0;
	t1=mulx(x1-x3,y1-y3,x4-x3,y4-y3)*mulx(x2-x3,y2-y3,x4-x3,y4-y3);
	t2=mulx(x3-x1,y3-y1,x2-x1,y2-y1)*mulx(x4-x1,y4-y1,x2-x1,y2-y1);
	if(t1<=0&&t2<=0)
		return 1;
	else
		return 0;
}

int findr(int x)
{
	int r=x;
	while(set[r]!=r)
		r=set[r];
	return r;
}

void merge(int x,int y)
{
	int rx=findr(x),ry=findr(y);
	if(rx<ry)
		set[ry]=rx;
	else if(rx>ry)
		set[rx]=ry;
}

int main()
{
	int n,t,i,j,top,ans;
	char command;
	scanf("%d",&t);
	while(t-->0)
	{
		for(i=1;i<M;i++)
			set[i]=i;
		scanf("%d",&n);
		getchar();
		top=1;
		while(n-->0)
		{
			scanf("%c",&command);
			getchar();
			if(command=='Q')
			{
				scanf("%d",&i);
				getchar();
				j=findr(i);
				ans=0;
				for(i=1;i<top;i++)
					if(findr(i)==j)
						ans++;
				printf("%d\n",ans);
			}
			else
			{
				scanf("%lf%lf%lf%lf",&x1[top],&y1[top],&x2[top],&y2[top]);
				getchar();
				for(i=1;i<top;i++)
					if(iscross(x1[i],y1[i],x2[i],y2[i],x1[top],y1[top],x2[top],y2[top])==1)
						merge(i,top);
				top++;
			}
		}
		if(t>0)
			printf("\n");
	}
	return 0;
}