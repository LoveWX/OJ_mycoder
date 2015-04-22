#include<stdio.h>
#include<math.h>

int main()
{
	unsigned long p;
	while(scanf("%lu",&p)!=EOF)
	{
		while(p>18)
			p=(unsigned long)ceil(ceil(p/9.0)/2.0);
		if(p<=9)
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
	}
	return 0;
}
