#include<iostream>
using namespace std;

struct price
{
	long shops[5];
};
struct shop
{
	long prices[5];
};
price p[5];
shop s[5];
int pn,sn,m;

int cmp1(const void *a,const void *b)
{
	return ((price*)a)->shops[m]-((price*)b)->shops[m];
}

int cmp2(const void *aa,const void *bb)
{
	int i;
	shop *a=(shop*)aa;
	shop *b=(shop*)bb;
	for(i=0;i<pn;i++)
		if(a->prices[i]!=b->prices[i])
			return a->prices[i]-b->prices[i];
	return 0;
}

int main()
{
	int tcase,d=1,i,j,maxp,temp;
	while(scanf("%d",&tcase)!=EOF)
	{
		while(tcase-->0)
		{
			scanf("%d%d",&pn,&sn);
			maxp=2147483640;
			for(i=0;i<pn;i++)
				for(j=0;j<sn;j++)
				{
					scanf("%d",&temp);
					p[j].shops[i]=temp;
					if(temp<maxp)
					{
						m=i;
						maxp=temp;
					}
				}
			qsort(p,sn,sizeof(price),cmp1);
			for(i=0;i<pn;i++)
				for(j=0;j<sn;j++)
					s[i].prices[j]=p[j].shops[i];
			qsort(s,pn,sizeof(shop),cmp2);
			printf("Scenario #%d:\n",d++);
			m=1;
			for(i=0;i<pn;i++)
				for(j=0;j<sn;j++)
					if(m==1)
					{
						printf("%d",s[i].prices[j]);
						m=0;
					}
					else
						printf(" %d",s[i].prices[j]);
			printf("\n\n");
		}
	}
	return 0;
}