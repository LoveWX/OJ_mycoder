#include<stdio.h>

int main()
{
	int a,b;
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a==0)
			break;
		if(a*100%b==0)
			a=0;
		else
			a=b-a*100%b;
		printf("%02d",a);
		for(a+=b;a<100;a+=b)
			printf(" %02d",a);
		printf("\n");
	}
	return 0;
}