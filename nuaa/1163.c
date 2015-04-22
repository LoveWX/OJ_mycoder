#include<iostream>
#include<algorithm>
using namespace std;

int posx[1000],posy[1000];
double slope[1000];
int top;

double getslope(int a,int b)
{
	if(posx[a]==posx[b])
		return 2000.0;
	return (double)(posy[a]-posy[b])/(posx[a]-posx[b]);
}

int main()
{
	int i,j,k,n,longest,temp;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d%d",&i,&j);
			printf("1\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&posx[i],&posy[i]);
		}
		longest=1;
		for(i=0;i<n;i++)
		{
			top=0;
			for(j=0;j<n;j++)
			{
				if(i==j)
					continue;
				slope[top++]=getslope(i,j);
			}
			sort(&slope[0],&slope[top]);
			temp=1;
			for(k=1;k<top;k++)
			{
				if(slope[k-1]==slope[k])
				{
					temp++;
				}
				else
				{
					if(temp>longest)
						longest=temp;
					temp=1;
				}
			}
			if(temp>longest)
				longest=temp;
		}
		printf("%d\n",longest+1);
	}
	return 0;
}
