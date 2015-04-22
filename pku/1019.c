#include<stdio.h>
#include<math.h>

__int64 countn[7]={0,0,9,189,2889,38889,488889};
__int64 total[7]={0,45,9045,1395495,189414495,23750235000};
char small[47]="0112123123412345123456123456712345678123456789";

int main()
{
	int ncase;
	__int64 a,i,d,n;
	while(scanf("%d",&ncase)!=EOF)
	{
		while(ncase-->0)
		{
			scanf("%I64d",&n);
			if(n<=45)
			{
				printf("%c\n",small[n]);
				continue;
			}
			if(n==9045||n==1395495||n==189414495)
			{
				printf("9\n");
				continue;
			}

			i=1;
			while(n>total[i])
				i++;

			n-=total[i-1];
			a=countn[i]+i;
			d=i;
			d=(int)floor((d-a-a+sqrt(((__int64)a+a-d)*(a+a-d)+d*n*8.0))*0.5/d);
			i=d*a+(d-1)*d/2*i;
			if(n!=i)
				n-=i;

			a=1;
			i=2;
			while(n>countn[i])
			{
				i++;
				a*=10;
			}
			n-=countn[i-1];
			if(i==2)
				printf("%I64d\n",n);
			else
			{
				char ans[6];
				sprintf(ans,"%I64d",a+(n-1)/(i-1));
				n=n%(i-1);
				if(n==0)
					n=i-1;
				n--;
				printf("%c\n",ans[n]);
			}
		}
	}
	return 0;
}