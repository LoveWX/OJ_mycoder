#include<stdio.h>

int main()
{
	float dofp,d,temp;
	int x,y,n,t;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		t=0;
		temp=y;
		dofp=temp/x;
		scanf("%d",&n);
		for(;n>0;n--)
		{
			scanf("%d%d",&x,&y);
			temp=y;
			d=temp/x;
			if(dofp==d)
				t++;
		}
		printf("%d\n",t);
	}
	return 0;
}