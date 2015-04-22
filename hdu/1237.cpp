#include<stdio.h>

double numstack[201];
int numstacktop;
char operstack[201];
int operstacktop;
char temp[201];

int main()
{
	int num,i,j;
	char c;
	double dnum;
	while (1)
	{
		scanf("%d",&num);
		c=getchar();
		if(num==0&&c!=' ')
			break;
		if(c!=' ')
		{
			printf("%d.00\n",num);
			continue;
		}
		numstacktop=0;
		operstacktop=0;
		numstack[numstacktop++]=num;
		while(1)
		{
			scanf("%s",temp);
			if(temp[0]=='+'||temp[0]=='-')
			{
				scanf("%d",&num);
				numstack[numstacktop++]=num;
				operstack[operstacktop++]=temp[0];
			}
			else if(temp[0]=='*'||temp[0]=='/')
			{
				dnum=numstack[numstacktop-1];	
				scanf("%d",&num);
				if(temp[0]=='*')
					dnum*=num;
				else
					dnum/=num;
				numstack[numstacktop-1]=dnum;
			}
			c=getchar();
			if(c!=' ')
				break;
		}
		dnum=numstack[0];
		for(i=0,j=1;i<operstacktop;i++,j++)
		{
			if(operstack[i]=='+')
				dnum+=numstack[j];
			else
				dnum-=numstack[j];
		}
		printf("%.2lf\n",dnum);
	}
	return 0;
}
