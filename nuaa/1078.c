#include<stdio.h>

void main()
{
	int i,s,sum;
	while(scanf("%d",&s)!=EOF)
	{
		if(s==2)
		{
			printf("3\n");
			continue;
		}
		sum=0;
		for(i=1;sum<s;i++)
			sum+=i;
		i--;
		if(sum==s)
		{
			printf("%d\n",i);
			continue;
		}
		else
		{
			if((sum-s)%2==0)
				printf("%d\n",i);
			else
			{
				if((sum+i+1-s)%2==0)
					printf("%d\n",i+1);
				else
					printf("%d\n",i+2);
			}
		}
		//printf("%d %d",i,sum);
	}
}