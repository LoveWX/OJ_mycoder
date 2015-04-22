#include <stdio.h>

int main()
{
	int flag,k,i,j,ii,t1,t2;
	while(scanf("%d",&k)!=EOF)
	{
		flag=1;
		for(i=100;i%k!=0;i++);
		for(;i<300;i+=k)
		{
			if(i%k!=0)
				continue;
			t1=0;
			for(j=i%100*10;t1<10;j++,t1++)
			{
				if(j%k!=0)
					continue;
				t2=0;
				for(ii=j%100*10;t2<10;ii++,t2++)
				{
					if(ii%k==0)
					{
						flag=0;
						printf("%d%d%d\n",i,t1,t2);
					}
				}
			}
		}
		if(300%k==0)
		{
			flag=0;
			printf("30000\n");
		}
		if(flag)
			printf("No\n");
	}
	return 0;
}
