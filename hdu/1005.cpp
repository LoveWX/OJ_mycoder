#include<stdio.h>

int main()
{
	int f1,f2,f3,i,flag,t;
	long a,b,n;
	while(1)
	{
		scanf("%ld%ld%ld",&a,&b,&n);
		if(n==0)
			break;
		int r[7][7]={0};
		a%=7;
		b%=7;
		f1=1;
		f2=1;
		f3=1;
		flag=0;
		for(i=3;i<=n;i++)
		{
			f3=(a*f2+b*f1)%7;
			r[f1][f2]=i;
			f1=f2;
			f2=f3;
			if(r[f1][f2]!=0&&flag==0)
			{
				flag=1;
				t=i-r[f1][f2]+1;
				i=r[f1][f2]-3;
				n=(n-i)%t+i;
				if(n==i)
					n+=t;
				if(n-1==i)
				{
					f3=f1;
					break;
				}
				if(n-2==i)
				{
					f3=f2;
					break;
				}
				i+=2;
			}
		}
		printf("%d\n",f3);
	}
	return 0;
}