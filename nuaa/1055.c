#include<stdio.h>
#define min(A,B) ((A)<(B)?(A):(B))

int main()
{
	long a,b,c,x,y,z,t1,t2,t3,t4,m;
    while(1)
	{
		scanf("%ld%ld%ld%ld%ld%ld",&a,&b,&c,&x,&y,&z);
		if(a==0&&b==0&&c==0&&x==0&&y==0&&z==0)
			break;
        if(x<0)
			x=-x;
		if(y<0)
			y=-y;
		if(z<0)
			z=-z;
		if(x==0||y==0||z==0)
			m=x*x+y*y+z*z;
		if(z==c)
		{
			t1=(c+y)*(c+y)+x*x;
			t2=(c+x)*(c+x)+y*y;
			t3=(c+b-y)*(c+b-y)+(x+b)*(x+b);
			t4=(c+a-x)*(c+a-x)+(a+y)*(a+y);
			m=min(min(t1,t2),min(t3,t4));
        }
        if(x==a)
		{
			t1=(a+z)*(a+z)+y*y;
			t2=(a+y)*(a+y)+z*z;
			t3=(c+a-z)*(c+a-z)+(y+c)*(y+c);
			t4=(b+a-y)*(b+a-y)+(b+z)*(b+z);
			m=min(min(t1,t2),min(t3,t4));
        }
        if(y==b)
		{
			t1=(b+x)*(b+x)+z*z;
			t2=(b+z)*(b+z)+x*x;
			t3=(c+b-z)*(c+b-z)+(x+c)*(x+c);
			t4=(b+a-x)*(b+a-x)+(a+z)*(a+z);
			m=min(min(t1,t2),min(t3,t4));
		}
		printf("%ld\n",m);
	}
    return 0;
}