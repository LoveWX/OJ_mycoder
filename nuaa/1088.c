#include<stdio.h>

int main()
{
    __int64 a,b,n,t;
    while(scanf("%I64d %I64d %I64d",&a,&b,&n)!=EOF)
    {
        t=1;
        while(b!=0)
        {
            if(b%2==1)
                t=t*a%n;
            a=a*a%n;
            b/=2;
        }
        printf("%I64d\n",t);
    }
    return 0;
} 