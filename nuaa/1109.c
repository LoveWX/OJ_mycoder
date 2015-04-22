#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
bool isprime[870];
__int64 sta[870][50][50];

__int64 dp(int num,int min,int len)
{
    if(sta[num][min][len]!=-1)
        return sta[num][min][len];
    __int64 minsum=min*len;
    __int64 maxsum=len*min+len*(len-1)/2;
    if(num<minsum||num>maxsum)
	{
        sta[num][min][len]=0;
        return 0;
    }
    if(num==minsum||num==maxsum)
	{
        sta[num][min][len]=1;
        return 1;
    }
    sta[num][min][len]=dp(num-min,min,len-1)+dp(num-min,min+1,len-1);
    return sta[num][min][len];
}

void getprime()//false means it is a prime
{
    int i,j;
    isprime[0]=1;
    isprime[1]=1;
    isprime[2]=0;
    isprime[3]=0;
    i=2;
    while(i<=861)
    {
        if(!isprime[i])
        {
            for(j=i+i;j<=861;j+=i)
                isprime[j]=1;
        }
        i++;
    }
}

int main()
{
    int n,minnum,maxnum,i;
    __int64 ans;
    getprime();
    while(scanf("%d",&n)!=EOF)
    {
        for( i=1;i<=865;i++)
            for(int j=1;j<=42;j++)
                for(int k=1;k<=42;k++)
                    sta[i][j][k]=-1;
		ans=0;
		minnum=n;
		maxnum=n*(n+1)/2;
		for(i=minnum;i<=maxnum;i++)
		{
			if(!isprime[i])
				ans+=dp(i,1,n);
					
		}
		printf("%I64d\n",ans);
		//printf("Level %d,Num %d=%d\n",n,num,dp(num,1,n));
    }
    return 0;
}
