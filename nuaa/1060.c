#include<stdio.h>

int main()
{
	long int t,num[500];
	int i,j,n,flag;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		if(n%2==1)
		{
			printf("no\n");
			for(;n>0;n--)
				scanf("%ld",&t);
			continue;
		}
		flag=1;
		for(i=0;i<n;i++)
			scanf("%ld",&num[i]);
		t=num[0]+num[n-1];
		i=1;
		j=n-2;
		while(i<j)
		{
			if(num[i]+num[j]!=t)
			{
				flag=0;
				break;
			}
			i++;
			j--;
		}
		if(flag==1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}