#include<stdio.h>

long min(int a,int b,int c,int d)
{
	if(a>b)
		a=b;
	if(c>d)
		c=d;
	if(a<c)
		return a;
	return c;
}

int main()
{
	char cst[3]="st",cnd[3]="nd",crd[3]="rd",cth[3]="th";
	char *sp;
	long r[5843]={0,1,2,3,4,5,6,7};
	int a=4,b=3,c=2,d=2,i;
	for(i=8;i<=5842;i++)
	{
		r[i]=min(r[a]*2,r[b]*3,r[c]*5,r[d]*7);
		for(;r[a]*2<=r[i];a++);
		for(;r[b]*3<=r[i];b++);
		for(;r[c]*5<=r[i];c++);
		for(;r[d]*7<=r[i];d++);
	}
	while(1)
	{
		scanf("%d",&i);
		if(i==0)
			break;
		b=i;
		i%=100;
		a=i%10;
		if(a==1&&i!=11)
			sp=cst;
		else if(a==2&&i!=12)
			sp=cnd;
		else if(a==3&&i!=13)
			sp=crd;
		else
			sp=cth;
		printf("The %d%s humble number is %ld.\n",b,sp,r[b]);
	}
	return 0;
}