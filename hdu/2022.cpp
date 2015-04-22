#include<stdio.h>

int main()
{
	int r,c,ansr,ansc,i,j,t1,t2,m,mabs;
	while(scanf("%d%d",&r,&c)!=EOF)
	{
		ansr=0;
		ansc=0;
		mabs=-1;
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
			{
				scanf("%d",&t1);
				if(t1<0)
					t2=-t1;
				else
					t2=t1;
				if(t2>mabs)
				{
					m=t1;
					mabs=t2;
					ansr=i;
					ansc=j;
				}
			}
		printf("%d %d %d\n",ansr,ansc,m);	
	}
	return 0;
}

