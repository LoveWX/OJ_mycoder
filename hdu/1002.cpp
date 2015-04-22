#include<stdio.h>
#include<string.h>

char num1[1002],num2[1002],ans[1002];

int main()
{
	int l,l1,l2,t,n,ncase,carry;
	while(scanf("%d",&n)!=EOF)
	{
		for(ncase=1;ncase<=n;ncase++)
		{
			t=0;
			carry=0;
			scanf("%s%s",num1,num2);
			l1=strlen(num1)-1;
			l2=strlen(num2)-1;
			l=l1;
			if(l1>l2)
				l=l2;
			while(l>=0)
			{
				carry=num1[l1--]-'0'+num2[l2--]-'0'+carry;
				ans[t++]=carry%10+'0';
				carry/=10;
				l--;
			}
			while(l1>=0)
			{
				carry=num1[l1--]-'0'+carry;
				ans[t++]=carry%10+'0';
				carry/=10;
			}
			while(l2>=0)
			{
				carry=num2[l2--]-'0'+carry;
				ans[t++]=carry%10+'0';
				carry/=10;
			}
			if(carry>0)
				ans[t++]=carry+'0';
			printf("Case %d:\n%s + %s = ",ncase,num1,num2);
			for(t--;t>=0;t--)
				printf("%c",ans[t]);
			if(ncase==n)
				printf("\n");
			else
				printf("\n\n");
		}
	}
	return 0;
}