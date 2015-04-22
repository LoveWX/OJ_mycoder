#include<stdio.h>

int main()
{
	int i,j,n;
	long a[1002]={-1},m[1002]={0};
	__int64 sum[1002],max;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		for(i=1;i<=n;i++)
		{
			max=a[i];	
			for(j=1;j<i;j++)
				if(a[i]>m[j]&&a[i]+sum[j]>max)
					max=a[i]+sum[j];
			m[i]=a[i];
			sum[i]=max;
		}
		max=0;
		for(i=1;i<=n;i++)
			if(sum[i]>max)
				max=sum[i];
		printf("%I64d\n",max);
	}
	return 0;
}