#include<stdio.h>

int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int n[26],t[26];

int main()
{
	int i,j,l1,l2,carry;
	char c;
	while(1)
	{
		l1=0;
		do
		{
			scanf("%d",&t[l1++]);
			c=getchar();
		}while(c==',');
		for(i=0,j=l1-1;j>=0;i++,j--)
			n[i]=t[j];
		for(;i<26;i++)
			n[i]=0;
		l2=0;
		do
		{
			scanf("%d",&t[l2++]);
			c=getchar();
		}while(c==',');
		if(l1==1&&l2==1&&n[0]==0&&t[0]==0)
			break;
		carry=0;
		for(i=0,j=l2-1;j>=0;i++,j--)
		{
			n[i]=n[i]+t[j]+carry;
			carry=n[i]/prime[i];
			n[i]%=prime[i];
		}
		for(;i<26;i++)
		{
			n[i]+=carry;
			carry=n[i]/prime[i];
			n[i]%=prime[i];
		}
		for(i=25;i>=0;i--)
			if(n[i]>0)
				break;
		printf("%d",n[i]);
		for(i--;i>=0;i--)
			printf(",%d",n[i]);
		printf("\n",carry);
	}
	return 0;
}