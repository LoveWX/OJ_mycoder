#include<stdio.h>

long pos[100001][11]; 

long max2(long x,long y)
{
	if(x>y)
		return x;
	return y;
}

long max3(long x,long y,long z)
{
	if(x<y)
		x=y;
	if(x>z)
		return x;
	return z;
}

int main()
{
	long i,mt,t;
	int j;
	while(1)
	{
		scanf("%ld",&i);
		if(i==0)
			break;
		mt=-1;
		while(i-->0)
		{
			scanf("%ld%ld",&j,&t);
			pos[t][j]++;
			if(t>mt)
				mt=t;
		}
		pos[1][0]=0;
		pos[1][1]=0;
		pos[1][2]=0;
		pos[1][3]=0;
		pos[1][7]=0;
		pos[1][8]=0;
		pos[1][9]=0;
		pos[1][10]=0;
		pos[2][0]=0;
		pos[2][1]=0;
		pos[2][2]=0;
		pos[2][8]=0;
		pos[2][9]=0;
		pos[2][10]=0;
		pos[3][0]=0;
		pos[3][1]=0;
		pos[3][9]=0;
		pos[3][10]=0;
		pos[4][0]=0;
		pos[4][10]=0;
		for(i=2;i<=mt;i++)
		{
			pos[i][0]+=max2(pos[i-1][0],pos[i-1][1]);
			pos[i][10]+=max2(pos[i-1][9],pos[i-1][10]);
			for(j=1;j<10;j++)
				pos[i][j]+=max3(pos[i-1][j-1],pos[i-1][j],pos[i-1][j+1]);
		}
		i=-1;
		for(j=0;j<=10;j++)
			if(pos[mt][j]>i)
				i=pos[mt][j];
		printf("%ld\n",i);
		for(i=1;i<=mt;i++)
			for(j=0;j<=10;j++)
				pos[i][j]=0;
	}
	return 0;
}