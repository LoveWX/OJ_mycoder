#include<stdio.h>

typedef struct
{
	int x;//weight
	int p;//price
}xp;

int n,s;
int pf[100],w[100],b[100];
xp point[50000];

int largest(int low,int high,int i)
{
	int j,u=low-1;
	for(j=low;j<=high;j++)
	{
		int ww=point[j].x+w[i];
		if(ww<=s)
			u=j;
	}
	return u;
}

int knap()
{
	int ww,pp;
	int low=0,high=1,next=2,i,j,k,u;
	b[0]=0;
	b[1]=2;
	point[0].x=0;
	point[0].p=0;
	point[1].x=w[0];
	point[1].p=pf[0];
	for(i=1;i<n;i++)
	{
		k=low;
		u=largest(low,high,i);
		for(j=low;j<=u;j++)
		{
			ww=point[j].x+w[i];
			pp=point[j].p+pf[i];
			while((k<=high)&&(point[k].x<ww))
			{
				point[next].x=point[k].x;
				point[next++].p=point[k++].p;
			}
			if(k<=high&&point[k].x==ww)
				if(pp<point[k].p)
					pp=point[k++].p;
			if(pp>point[next-1].p)
			{
				point[next].x=ww;
				point[next++].p=pp;
			}
			while(k<=high&&point[k].p<=point[next-1].p)
				k++;
		}
		while(k<=high)
		{
			point[next].x=point[k].x;
			point[next++].p=point[k++].p;
		}
		low=high+1;
		high=next-1;
		b[i+1]=next;
	}
	return point[next-1].p;
}

int knap2()
{
	int a=-1,b=-1;
	if(w[0]>s&&w[1]>s)
		return 0;
	if(w[0]+w[1]<=s)
		return pf[0]+pf[1];
	if(w[0]<=s)
		a=pf[0];
	if(w[1]<=s)
		b=pf[1];
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int i;
	while(scanf("%d%d",&n,&s)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&pf[i],&w[i]);
		if(n==1)
		{
			if(w[0]<=s)
				printf("%d\n",pf[0]);
			else
				printf("0\n");
			continue;
		}
		if(n==2)
		{
			printf("%d\n",knap2());
			continue;
		}
		printf("%d\n",knap());
	}
	return 0;
}
