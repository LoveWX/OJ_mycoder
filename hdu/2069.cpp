#include<stdio.h>

int elem[5]={1,5,10,25,50};
int c1[251][101],c2[251][101];
int r[251];
int main()
{
	int i,j,k,t;
	c1[0][0]=1;
	for(i=0;i<5;i++)
	{
		for(j=0;j<=250;j++)
			for(k=0;k*elem[i]+j<=250;k++)
				for(t=0;t+k<=100;t++)
					c2[j+k*elem[i]][t+k]+=c1[j][t];
		for(j=0;j<=250;j++)
			for(k=0;k<=100;k++)
			{
				c1[j][k]=c2[j][k];
				c2[j][k]=0;
			}
	}
	for(i=0;i<=250;i++)
	{
		r[i]=0;
		for(j=0;j<=100;j++)
			r[i]+=c1[i][j];
	}
	r[0]=1;
	while(scanf("%d",&i)!=EOF)
		printf("%d\n",r[i]);
	return 0;
}