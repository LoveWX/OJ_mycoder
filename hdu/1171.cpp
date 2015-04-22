#include<stdio.h>
#define MAX 250001
bool cc[MAX];
int v[50],m[50];

int main()
{
    int i,j,k,n,sum,t;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
            break;
        if(n==0)
        {
            printf("0 0\n");
            continue;
        }
		for(i=0;i<n;i++)
			scanf("%d%d",&v[i],&m[i]);
		sum=v[0]*m[0];
		for(i=0;i<=sum;i+=v[0])
			cc[i]=1;
		for(i=1;i<n;i++)
		{
			t=v[i]*m[i];
			for(j=0;j<=sum;j++)
				if(!cc[j])
					continue;
				else
				{
					for(k=v[i];k<=t;k+=v[i])
						cc[k+j]=1;
				}
			sum+=t;
		}
        for(i=sum/2;i>=0;i--)
            if(cc[i])
			{
				cc[i]=0;
                break;
			}
        printf("%d %d\n",sum-i,i);
		for(i=sum;i>=0;i--)
			cc[i]=0;
    }
    return 0;
}