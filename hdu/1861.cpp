#include<stdio.h>

int boatused[101];
int starthour[101];
int startminute[101];

void init()
{
	int i;
	for(i=0;i<101;i++)
		boatused[i]=0;
}

int main()
{
	int num,h,m;
	int totaltime=0,renttime=0;
	char c,thetime[6];
	while(1)
	{
		scanf("%d",&num);
		if(num==-1)
			break;
		getchar();
		c=getchar();
		getchar();
		scanf("%s",thetime);
		if(num>0)
		{
			if(c=='S')
			{
				boatused[num]=1;
				starthour[num]=(thetime[0]-'0')*10+thetime[1]-'0';
				startminute[num]=(thetime[3]-'0')*10+thetime[4]-'0';
			}
			else if(c=='E')
			{
				if(boatused[num]==1)
				{
					h=(thetime[0]-'0')*10+thetime[1]-'0';
					m=(thetime[3]-'0')*10+thetime[4]-'0';
					totaltime+=(h-starthour[num])*60+m-startminute[num];
					renttime++;
					boatused[num]=0;
				}
			}
		}
		else
		{
			if(renttime==0)
				printf("0 0\n");
			else
				printf("%d %d\n",renttime,(int)((double)totaltime/renttime+0.5));
			init();
			totaltime=0;
			renttime=0;
		}
	}
	return 0;
}
