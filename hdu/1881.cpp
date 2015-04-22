#include<iostream>
#include<algorithm>
using namespace std;

int n,ans;

struct DG 
{
	int happiness;
	int lasttime;
	int endtime;
};

DG dg[30];

bool cmp(const DG& a,const DG& b)
{
	if(a.endtime==b.endtime)
		return a.lasttime>b.lasttime;
	return a.endtime<b.endtime;
}

void DFS(int index,int gothappiness,int currenttime)
{
	if(index>=n)
	{
		if(gothappiness>ans)
			ans=gothappiness;
		return;
	}
	DFS(index+1,gothappiness,currenttime);
	if(dg[index].lasttime+currenttime<=dg[index].endtime)
		DFS(index+1,gothappiness+dg[index].happiness,currenttime+dg[index].lasttime);
}

int main()
{
	int i;
	while (1)
	{
		scanf("%d",&n);
		if(n<0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&dg[i].happiness,&dg[i].lasttime,&dg[i].endtime);
		}
		sort(&dg[0],&dg[n],cmp);
		ans=0;
		DFS(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
