#include<stdio.h>
#include<string.h>

int main()
{
	int i,len,ta,te,ti,to,tu,flag=1,n;
	char str[100];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n-->0)
		{
			gets(str);
			ta=0;
			te=0;
			ti=0;
			to=0;
			tu=0;
			len=strlen(str);
			for(i=0;i<len;i++)
				if(str[i]=='a'||str[i]=='A')
					ta++;
				else if(str[i]=='e'||str[i]=='E')
					te++;
				else if(str[i]=='i'||str[i]=='I')
					ti++;
				else if(str[i]=='o'||str[i]=='O')
					to++;
				else if(str[i]=='u'||str[i]=='U')
					tu++;
			if(flag==1)
				flag=0;
			else
				printf("\n");
			printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",ta,te,ti,to,tu);
		}
	}
	return 0;
}