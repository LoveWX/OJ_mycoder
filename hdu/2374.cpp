#include<stdio.h>

__int64 s[51];

int main()
{
	int n,i,j;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%I64d",&s[i]);
		for(i--;i>0;i--)
		{
			for(j=0;j<i;j++)
				s[j]+=s[i];
			s[0]+=s[i];
		}
		printf("%I64d\n",s[0]);
	}
	return 0;
}