#include<stdio.h>

int gcd(int a,int b)
{
    int c;
    while(b>0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int n,na,nb;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d%d",&na,&nb);
        n--;
        n--;
        na=gcd(na,nb);
        while(n>0)
        {
            scanf("%d",&nb);
            na=gcd(na,nb);
            n--;
        }
        printf("%d\n",na);
    }
    return 0;
}
