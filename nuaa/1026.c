#include <stdio.h>

int main()
{
    int n,t,max,min;
    while(scanf("%d",&n)!=EOF)
    {
		scanf("%d %d",&max,&min);
		if(max<min)
		{
			t=max;
			max=min;
			min=t;
		}
        for(n-=2;n>0;n--)
        {
            scanf("%d",&t);
            if(t>max)
				max=t;
            if(t<min)
				min=t;
        }
        printf("%d %d\n",max,min);
    }
    return 0;
}
