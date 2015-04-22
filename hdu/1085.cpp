#include<stdio.h>
#define M 8001
int main()
{
	int n1,n2,n5,i,k,m;
	while(1)
	{
		int c1[M]={0},c2[M]={0};
		scanf("%d%d%d",&n1,&n2,&n5);
		if(n1==0&&n2==0&&n5==0)
			break;
		for(i=0;i<=n1;i++)
			c1[i]=1;
		m=n1+n2+n2;
		for(i=0;i<=m;i++)
			for(k=0;k+i<=m;k+=2)
				c2[k+i]+=c1[i];
		for(i=0;i<=m;i++)
			c1[i]=0;
		m+=n5*5;
		for(i=0;i<=m;i++)
			for(k=0;k+i<=m;k+=5)
				c1[k+i]+=c2[i];
		for(i=1;i<=M;i++)
			if(c1[i]==0)
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}