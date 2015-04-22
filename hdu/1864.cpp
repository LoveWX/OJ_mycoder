#include<stdio.h>

double a,b,c,money[30];
int total;
double maxmoney,ans;

void DFS(int index,double currentmoney,double leftmoney)
{
	if(index>=total)
	{
		if(ans<currentmoney)
			ans=currentmoney;
		return;
	}
	if(currentmoney+leftmoney-money[index]>ans)
		DFS(index+1,currentmoney,leftmoney-money[index]);
	if(currentmoney+money[index]<=maxmoney&&currentmoney+leftmoney>ans)
		DFS(index+1,currentmoney+money[index],leftmoney-money[index]);
}

int main()
{
	int n,m,flag;
	double tempmoney,sum;
	char ch;
	while(1)
	{
		scanf("%lf%d",&maxmoney,&n);
		if(n==0)
			break;
		total=0;
		sum=0.0;
		while(n-->0)
		{
			scanf("%d",&m);
			flag=1;
			a=0;
			b=0;
			c=0;
			while(m-->0)
			{
				getchar();
				scanf("%c:%lf",&ch,&tempmoney);
				if(tempmoney>600)
				{
					flag=0;
					for(;m>0;m--)
					{
						getchar();
						scanf("%c:%lf",&ch,&tempmoney);
					}
					break;
				}
				if(ch=='A')
					a+=tempmoney;
				else if(ch=='B')
					b+=tempmoney;
				else if(ch=='C')
					c+=tempmoney;
				else
				{
					flag=0;
					for(;m>0;m--)
					{
						getchar();
						scanf("%c:%lf",&ch,&tempmoney);
					}
					break;
				}
			}
			if(a>600||b>600||c>600)
				flag=0;
			a=a+b+c;
			if(a>1000)
				flag=0;
			if(flag==1)
			{
				money[total++]=a;
				sum+=a;
			}
		}
		ans=0;
		DFS(0,0.0,sum);
		printf("%.2lf\n",ans);
	}
	return 0;
}
