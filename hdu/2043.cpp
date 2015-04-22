#include<stdio.h>
#include<string.h>

int main()
{
	char str[51];
	int n,i,s1,s2,s3,s4;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n-->0)
		{
			s1=0;
			s2=0;
			s3=0;
			s4=0;
			gets(str);
			i=strlen(str);
			if(i<8||i>16)
			{
				printf("NO\n");
				continue;
			}
			for(i--;i>=0;i--)
				if(str[i]>='A'&&str[i]<='Z')
					s1++;
				else if(str[i]>='a'&&str[i]<='z')
					s2++;
				else if(str[i]>='0'&&str[i]<='9')
					s3++;
				else if(str[i]=='~'||str[i]=='!'||str[i]=='@'||str[i]=='#'||str[i]=='$'||str[i]=='%'||str[i]=='^')
					s4++;
			if(s1>0)
				s1=1;
			if(s2>0)
				s2=1;
			if(s3>0)
				s3=1;
			if(s4>0)
				s4=1;
			if(s1+s2+s3+s4>=3)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}