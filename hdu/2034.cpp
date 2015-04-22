#include<iostream>
#include <algorithm>
using namespace std;

int num1[101];

int main()
{
	int i,n1,n2,t;
	while(1)
	{
		scanf("%d%d",&n1,&n2);
		if(n1==0&&n2==0)
			break;
		for(i=0;i<n1;i++)
			scanf("%d",&num1[i]);
		while(n2-->0)
		{
			scanf("%d",&t);
			for(i=0;i<n1;i++)
				if(num1[i]==t)
				{
					num1[i]=num1[--n1];
					break;
				}
		}
		if(n1<=0)
		{
			printf("NULL\n");
			continue;
		}
		sort(num1,num1+n1);
		for(i=0;i<n1;i++)
			printf("%d ",num1[i]);
		printf("\n");
	}
	return 0;
}

