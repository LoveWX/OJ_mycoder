#include<stdio.h>

int score[101];

int main()
{
	int n,t;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(t=0;t<=100;t++)
			score[t]=0;
		while(n-->0)
		{
			scanf("%d",&t);
			score[t]++;
		}
		scanf("%d",&t);
		printf("%d\n",score[t]);
	}
	return 0;
}
