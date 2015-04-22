#include<iostream>
#include<algorithm>
using namespace std;

const int SIZE_Length=1002;//����SIZE_LengthΪ���ܵ���󳤶�
const int SIZE_Width=1002;//����SIZE_WidthΪ���ܵ������

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
	int x,y,n,i,j,xx,yy;
	int ncase,tcase,ques;
	char kind;
	while(scanf("%d",&ncase)!=EOF)
	{
		for(tcase=1;tcase<=ncase;tcase++)
		{
			for(i=1;i<SIZE_Length;i++)
			{
				for(j=1;j<SIZE_Width;j++)
				{
					a[i][j]=1;
					c[i][j]=0;
				}
			}
			printf("Case %d:\n",tcase);
			scanf("%d",&ques);
			getchar();
			while(ques-->0)
			{
				scanf("%c",&kind);
				if(kind=='A')
				{
					scanf("%d %d %d",&x,&y,&n);
					getchar();
					a[x+1][y+1]+=n;
					modify(x+1,y+1,n);
				}
				else if(kind=='D')
				{
					scanf("%d %d %d",&x,&y,&n);
					getchar();
					i=a[x+1][y+1];
					if(i<n)
						n=i;
					a[x+1][y+1]-=n;
					modify(x+1,y+1,-n);
				}
				else if(kind=='M')
				{
					scanf("%d %d %d %d %d",&x,&y,&xx,&yy,&n);
					getchar();
					i=a[x+1][y+1];
					if(i<n)
						n=i;
					a[x+1][y+1]-=n;
					modify(x+1,y+1,-n);
					a[xx+1][yy+1]+=n;
					modify(xx+1,yy+1,n);
				}
				else
				{
					scanf("%d %d %d %d",&x,&y,&xx,&yy);
					getchar();
					if(x<xx)
						i=xx-x+1;
					else
						i=x-xx+1;
					if(y<yy)
						j=yy-y+1;
					else
						j=y-yy+1;
					printf("%ld\n",sum(x+1,y+1,xx+1,yy+1)+i*j);
				}
			}
		}
	}
	return 0;
}