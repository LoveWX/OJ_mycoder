#include<stdio.h>

__int64 ans;
__int64 used[2004];

void work(int n)
{
    int i;
    __int64 lastans=0;
    if(used[n]>=0)
    {
        ans+=used[n];
        return;
    }
    lastans=ans;
    ans++;
    for(i=1;i+i<=n;i++)
        work(i);
    used[n]=ans-lastans;
    if(n%2==0)
        used[n+1]=used[n];
    else
        used[n-1]=used[n];
}

int main()
{
    int n,i;
    for(i=1;i<=2000;i++)
        used[i]=-1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=1)
        {
            printf("%d\n",n);
            continue;
        }
        if(n%2==1)
            n--;
        ans=0;
        work(n);
        printf("%I64d\n",ans);
    }
    return 0;
}
