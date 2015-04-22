#include<iostream>
using namespace std;
#define M 50000
struct times
{
	int begin;
	int end;
};
times t[M];

int cmp(const void *a, const void *b)
{
	return ((struct times*)a)->end-((struct times*)b)->end;
}
 
int main()
{
	int i,j,k,tcase,d=1,n,e;
	while(scanf("%d",&tcase)!=EOF)
	{
		while(tcase-->0)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d%d%d",&k,&t[i].begin,&t[i].end);
				k--;
				t[i].begin+=k*3000;
				t[i].end+=k*3000;
			}
			qsort(t,n,sizeof(times),cmp);
			k=1;
			e=t[0].end;
			i=0;
			while(i<n)
			{
				for(j=i+1;j<n&&t[j].begin<e;j++);
				if(j>=n)
					break;
				i=j;
				e=t[j].end;
				k++;
			}
			printf("Scenario #%d:\n%d\n\n",d++,k);
		}
	}
	return 0;
}