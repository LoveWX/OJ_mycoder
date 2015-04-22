#include<stdio.h>

#define N 317

int prime[N+1]={0,1};
int numofprime;

int main()
{
    int i=2,j,p,ans,n;
    while(i<=N)
    {
        if(prime[i]==0)
        {
            for(j=i+i;j<=N;j+=i)
                prime[j]=1;
            prime[numofprime++]=i;
        }
        i++;
    }
    while(scanf("%d",&n)!=EOF)
    {
        ans=1;
        i=0;
        p=2;
        while(n>1&&p*p<=100000)
        {
            if(n%p==0)
            {
                for(j=1,n/=p;n%p==0;j++,n/=p);
                j++;
                if(j%2==0)
                    ans=0;
            }
            else
                p=prime[++i];
        }
        if(n>1)
            ans=0;
        printf("%d\n",ans);
    }
    return 0;
}