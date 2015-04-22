#include<stdio.h>
#include<string.h>

int main()
{
	char str[1001];
	char name[1001];
	int i,j,n,l,len,flag,t;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		gets(str);
		len=strlen(str);
		while(n>0)
		{
			flag=0;
			gets(name);
			l=strlen(name);
			t=len-l+1;
			for(i=0;i<t;i++)
			{
				if(str[i]==name[0])
				{
					flag=1;
					for(j=1;j<l;j++)
						if(str[i+j]!=name[j])
						{
							flag=0;
							break;
						}
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				printf("yes\n");
			else
				printf("no\n");
			n--;
		}
	}
	return 0;
}