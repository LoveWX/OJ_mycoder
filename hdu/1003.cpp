#include<stdio.h>
#define MAX 100000
int main()
{
    int s,e,t,n,i,j,max;
    int a[MAX];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        max=a[0];
        s=e=0;
        for(j=1;j<n;j++)
        {
            if(a[j-1]>0)
                a[j]+=a[j-1];
            if(a[j]>max)
            {
                max=a[j];
                s=j;
                e=j;
            }
        }
        for(j=e;j>-1;j--)
        {
            if(a[j]<0)
                break;
            else
                s=j;
        }
		if(i>1)
			printf("\n");
		printf("Case %d:\n",i);
		printf("%d %d %d\n",max,s+1,e+1);
    }
    return 0;
}
