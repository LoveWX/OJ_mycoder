#include<stdio.h>

int main()
{
    int i,j,n;
    long num[1000][35]={0};
    num[0][0]=1;
    num[1][0]=2;
    num[2][0]=4;
    num[3][0]=7;
    for(i=4;i<1000;i++)
    {    for(j=0;j<35;j++)
            num[i][j]=num[i-1][j]+num[i-2][j]+num[i-4][j];
        for(j=0;j<34;j++)
            if(num[i][j]>100000000)
            {
                num[i][j+1]+=num[i][j]/100000000;
                num[i][j]%=100000000;
            }
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(i=34;i>0;i--)
            if(num[n-1][i]!=0)
                break;
        printf("%ld",num[n-1][i]);
        for(j=i-1;j>=0;j--)
            printf("%08ld",num[n-1][j]);
        printf("\n");
    }
    return 0;
}