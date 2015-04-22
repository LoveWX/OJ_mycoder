#include<stdio.h>

int main()
{
	int n,sum;
	char tch,c;
	scanf("%ld",&n);
	getchar();
	while(n>0)
	{
		n--;
		tch=getchar();
		c=tch;
		sum=1;
		while((tch=getchar())!='\n'&&tch!=-1)
		{
			if(c==tch)
				sum++;
			else
			{
				if(sum<=1)
					printf("%c",c);
				else
					printf("%d%c",sum,c);
				sum=1;
				c=tch;
			}
		}
		if(sum<=1)
			printf("%c",c);
		else
			printf("%d%c",sum,c);
		printf("\n");
	}
	return 0;
}