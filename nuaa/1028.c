#include<stdio.h>

int num[200000];

void swap(int* x,int* y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int a[],int p,int r)
{
	int i=p,j=r+1;
	int x=a[p];
	while(1)
	{
		while(a[++i]<x);
		while(a[--j]>x);
		if(i>=j)
			break;
		swap(a+i,a+j);
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}

void quicksort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

void main()
{
	long int n,i;
	while(scanf("%ld",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		quicksort(num,0,n-1);
		printf("%d",num[0]);
		for(i=1;i<n;i++)
			printf(" %d",num[i]);
		printf("\n");
	}
}