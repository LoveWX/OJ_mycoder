#include<stdio.h>
#include<string.h>

char c[1001][16];
int n[1001];
int tn;

int main()
{
	int flag,i,m;
	char temp[16];
	while(1)
	{
		scanf("%d",&m);
		if(m==0)
			break;
		getchar();
		tn=0;
		while(m>0)
		{
			gets(temp);
			flag=0;
			for(i=0;i<tn;i++)
				if(strcmp(c[i],temp)==0)
				{
					flag=1;
					n[i]++;
					break;
				}
			if(flag==0)
			{
				n[tn]=1;
				strcpy(c[tn++],temp);
			}
			m--;
		}
		for(i=0;i<tn;i++)
			if(n[i]>m)
			{
				m=n[i];
				flag=i;
			}
		printf("%s\n",c[flag]);
	}
	return 0;
}