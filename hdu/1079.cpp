#include<stdio.h>

int main()
{
	int y,m,d,t; 
	while(scanf("%d",&t)!=EOF)
	{
		 while(t-->0)
		 {
			 scanf("%d%d%d",&y,&m,&d);
			 if(((m==9||m==11)&&d==30)||(m+d)%2==0)
				 puts("YES");
			 else
				 puts("NO");
		 }
	}
	return 0;
}