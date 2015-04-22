#include<stdio.h>

void swap(double &a,double &b)
{
    double t=a;
    a=b;
    b=t;
}

void mysort(double *a)
{
	double temp; 
	int i,j,k; 
	for(i=0;i<4;i++)
	{
		k=i;
		for(j=i+1;j<4;j++)
			if(a[j]<a[k])
				k=j;
		if(k!=i) 
		{ 
			temp=a[i]; 
			a[i]=a[k];
			a[k]=temp; 
		} 
	}
}

int main()
{
    double x[4],y[4];
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3])!=EOF)
    {
        if(x[0]>x[1])
            swap(x[0],x[1]);
        if(y[0]>y[1])
            swap(y[0],y[1]);
        if(x[2]>x[3])
            swap(x[2],x[3]);
        if(y[2]>y[3])
            swap(y[2],y[3]);
		if(x[2]>=x[1]||y[2]>=y[1]||x[0]>=x[3]||y[0]>=y[3])
		{
			printf("0.00\n");
			continue;
		}
		mysort(x);
		mysort(y);
		printf("%.2lf\n",(x[2]-x[1])*(y[2]-y[1]));
    }
    return 0;
}