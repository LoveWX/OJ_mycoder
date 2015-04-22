#include<stdio.h>
#include<string.h>

char str[1000001];
char usedc[129];
int usedn[129];

int main()
{
	long max,b,t,len,nowl;
	int tu,flag,l,i;
	while(1)
	{
		scanf("%d",&l);
		getchar();
		if(l==0)
			break;
		gets(str);
		len=strlen(str);
		max=0;
		b=0;
		t=1;
		usedc[0]=str[0];
		usedn[0]=1;
		tu=1;
		nowl=1;
		while(t<len)
		{
			flag=1;
			for(i=0;i<tu;i++)
				if(usedc[i]==str[t])
				{
					flag=0;
					break;
				}
			if(flag==0)
			{
				nowl++;
				usedn[i]++;
				if(nowl>max)
					max=nowl;
			}
			else if(tu<l)
			{
				usedc[tu]=str[t];
				usedn[tu++]=1;
				nowl++;
				if(nowl>max)
					max=nowl;
			}
			else
			{
				while(tu>l-1)
				{
					for(i=0;i<tu;i++)
						if(str[b]==usedc[i])
							break;
					usedn[i]--;
					if(usedn[i]==0)
					{
						usedc[i]=usedc[--tu];
						usedn[i]=usedn[tu];
					}
					b++;
					nowl--;
				}
				usedc[tu]=str[t];
				usedn[tu++]=1;
				nowl++;
			}
			t++;
		}
		printf("%ld\n",max);
	}
	return 0;
}