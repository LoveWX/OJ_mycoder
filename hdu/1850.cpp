#include<stdio.h>

int main()
{
	int n,i,ans;
	long a,num[100];
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		a=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&num[i]);
			a^=num[i];
		}
		if(a==0)
		{
			printf("0\n");
			continue;
		}
		ans=0;
		for(i=0;i<n;i++)
			if((num[i]^a)<num[i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
