#include<stdio.h>

int main()
{
	long n;
	while(scanf("%ld",&n)!=EOF)
		if(n%4==2)
			printf("yes\n");
		else
			printf("no\n");
	return 0;
}
