#include<stdio.h>
#include<math.h>

int judge(unsigned long int n)
{
	int i;
	if(n==1||n==2)
		return 1;
	n++;
	for(i=2;n%2==0;n/=2);
	for(i=3;n%3==0;n/=3);
	if(n==1)
		return 1;
	else
		return 0;
}

void main()
{
	unsigned long int n;
	while(1)
	{
		scanf("%ld",&n);
		if(n==0)
			break;
		if(judge(n)==1)
			printf("yes\n");
		else
			printf("no\n");
	}
}