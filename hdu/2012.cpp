#include<stdio.h>

int prime[2592];

void findp()
{
	int i,j;
	prime[0]=1;
	prime[1]=1;
	for(i=2;i<=51;i++)
	{
		if(prime[i]==0)
			for(j=i+i;j<=2591;j+=i)
				prime[j]=1;
	}
}

int main()
{
	int x,y,flag,n;
	findp();
	while(1)
	{
		scanf("%d%d",&x,&y);
		if(x==0&&y==0)
			break;
		flag=1;
		n=x*x+x+41;
		while(x<=y)
		{
			if(n<2||prime[n]==1)
			{
				flag=0;
				break;
			}
			n=n+x+x+2;
			x++;
		}
		if(flag==1)
			printf("OK\n");
		else
			printf("Sorry\n");
	}
	return 0;
}