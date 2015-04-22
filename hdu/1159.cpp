#include<stdio.h>
#include<string.h>
#define M 5001
char si[M];
char sj[M];
int d[M][M];

int main()
{
    int i,j,m,n;
    si[0]='1';
    sj[0]='1';
    while(scanf("%s %s",si+1,sj+1)!=EOF)
    {
        m=strlen(si)-1;
        n=strlen(sj)-1;
        for(j=0;j<=n;j++)
            d[0][j]=0;
        for(i=1;i<=m;i++)
        {
            d[i][0]=0;
            for(j=1;j<=n;j++)
                if(si[i]==sj[j])
                    d[i][j]=d[i-1][j-1]+1;
                else
                {
                    if(d[i-1][j]>=d[i][j-1])
                        d[i][j]=d[i-1][j];
                    else
                        d[i][j]=d[i][j-1];
                }
        }
        printf("%d\n",d[m][n]);
    }
    return 0;
}