#include<stdio.h>

int main()
{
	char num[5];
	int n,i,t,sum;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		sprintf(num,"%d",n);
		sum=num[0]-'0'+num[1]-'0'+num[2]-'0'+num[3]-'0';
		t=0;
		i=n;
		while(i>0)
		{
			t+=i%12;
			i/=12;
		}
		if(t!=sum)
		{
			printf("%d is not a Sky Number.\n",n);
			continue;
		}
		t=0;
		i=n;
		while(i>0)
		{
			t+=i%16;
			i/=16;
		}
		if(t!=sum)
			printf("%d is not a Sky Number.\n",n);
		else
			printf("%d is a Sky Number.\n",n);
	}
	return 0;
}