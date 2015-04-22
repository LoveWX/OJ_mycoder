#include<stdio.h>

long int c[30][30];

int main()
{
	int n,m;
	c[1][0]=1;
	c[1][1]=1;
	c[2][0]=1;
	c[2][1]=2;
	c[2][2]=1;
	c[3][0]=1;
	c[3][1]=3;
	c[3][2]=3;
	c[3][3]=1;
	for(n=4;n<30;n++)
	{
		c[n][0]=1;
		c[n][n]=1;
		c[n][1]=n;
		c[n][n-1]=n;
		for(m=n-2;m>=2;m--)
			c[n][m]=c[n-1][m]+c[n-1][m-1];
	}
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)
			break;
		printf("%ld\n",c[n][m]);
	}
	return 0;
}