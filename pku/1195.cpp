#include<iostream>
#include<algorithm>
using namespace std;

const int SIZE_Length=1025;//����SIZE_LengthΪ���ܵ���󳤶�
const int SIZE_Width=1025;//����SIZE_WidthΪ���ܵ������

long c[SIZE_Length][SIZE_Width];//����c����

//lowbit(0)�����
//ע���±�ķ�ΧҪ������,�����������,����ƽ������

inline int lowbit(int x)//��Lowbit(x)��ֵ
{
	return x & (x ^ ( x - 1 ) );
}

int modify(long x1,long y1,long delta)//�޸ģ�������(x1,y1)���ֵ��delta
{
	for(long x=x1;x<=SIZE_Length;x+=lowbit(x))
		for(long y=y1;y<=SIZE_Width;y+=lowbit(y))
			c[x][y]+=delta;
		return 0;
}

long query(long x1,long y1)//��ѯ,��������(x1,y1)���ǰ׺�����
{
	long ans=0;
	for(int x=x1;x>0;x-=lowbit(x))
		for(int y=y1;y>0;y-=lowbit(y))
			ans+=c[x][y];
		return ans;
}

long sum(long x0,long y0,long x1,long y1)
//�����[(x0,y0),(x1,y1)]��Ԫ�صĺ�,(x0,y0)Ϊ���½�,(x1,y1)Ϊ���Ͻ�
//ע�Ᵽ֤��������Ϊ���������
{
	long temp;
	if(x0>x1)//��֤x0<=x1
	{
		temp=x0;
		x0=x1;
		x1=temp;
	}
	if(y0>y1)//��֤y0<=y1
	{
		temp=y0;
		y0=y1;
		y1=temp;
	}
	//����ֵΪ�������������ߵĲ�ѯ���
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
