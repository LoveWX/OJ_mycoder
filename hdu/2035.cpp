#include<stdio.h>

int main()
{
    int a,b,t;
    while(1)
    {
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)
			break;
        t=1;
        while(b!=0)
        {
            if(b%2==1)
                t=t*a%1000;
            a=a*a%1000;
            b/=2;
        }
        printf("%d\n",t);
    }
    return 0;
}