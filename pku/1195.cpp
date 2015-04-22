#include<iostream>
#include<algorithm>
using namespace std;

const int SIZE_Length=1025;//定义SIZE_Length为可能的最大长度
const int SIZE_Width=1025;//定义SIZE_Width为可能的最大宽度

long c[SIZE_Length][SIZE_Width];//定义c数组

//lowbit(0)会出错。
//注意下标的范围要大于零,如果不能满足,必须平移坐标

inline int lowbit(int x)//求Lowbit(x)的值
{
	return x & (x ^ ( x - 1 ) );
}

int modify(long x1,long y1,long delta)//修改，将坐标(x1,y1)点的值加delta
{
	for(long x=x1;x<=SIZE_Length;x+=lowbit(x))
		for(long y=y1;y<=SIZE_Width;y+=lowbit(y))
			c[x][y]+=delta;
		return 0;
}

long query(long x1,long y1)//查询,返回坐标(x1,y1)点的前缀数组和
{
	long ans=0;
	for(int x=x1;x>0;x-=lowbit(x))
		for(int y=y1;y>0;y-=lowbit(y))
			ans+=c[x][y];
		return ans;
}

long sum(long x0,long y0,long x1,long y1)
//求矩形[(x0,y0),(x1,y1)]中元素的和,(x0,y0)为左下角,(x1,y1)为右上角
//注意保证矩形区域为所求的区域
{
	long temp;
	if(x0>x1)//保证x0<=x1
	{
		temp=x0;
		x0=x1;
		x1=temp;
	}
	if(y0>y1)//保证y0<=y1
	{
		temp=y0;
		y0=y1;
		y1=temp;
	}
	//返回值为包含矩形四条边的查询结果
	return query(x1,y1)-query(x1,y0-1)-query(x0-1,y1)+query(x0-1,y0-1);
}

int a[SIZE_Length][SIZE_Width];

int main()
{
	int command,n,i,j,l,r,t,b,x,y;
	while(scanf("%d%d",&command,&n)!=EOF)
	{
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				c[i][j]=0;
				a[i][j]=0;
			}
		}
		while(1)
		{
			scanf("%d",&command);
			if(command==3)
				break;
			if(command==1)
			{
				scanf("%d%d%d",&x,&y,&t);
				if(t+a[x+1][y+1]<0)
				{
					t=-a[x+1][y+1];
				}
				a[x+1][y+1]+=t;
				modify(x+1,y+1,t);
			}
			else
			{
				scanf("%d%d%d%d",&l,&b,&r,&t);
				printf("%d\n",sum(l+1,b+1,r+1,t+1));
			}
		}
	}
	return 0;
}
