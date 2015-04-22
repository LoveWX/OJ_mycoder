#include<stdio.h>
#include<stdlib.h>

int cmp(const void *aa,const void *bb)
{
	int a=*((int *)(aa));
	int b=*((int *)(bb));
	if(a<0)
		a=-a;
	if(b<0)
		b=-b;
	return b-a;
}

int main()
{
	int n,i,a[101];
	while(1)
	{
		scanf("%d",&n);
		if(n<=0)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),cmp);
		printf("%d",a[0]);
		for(i=1;i<n;i++)
			printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}