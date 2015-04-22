#include<stdio.h>

int main()
{
	double c,t;
	int i;
	while(1)
	{
		scanf("%lf",&c);
		if(c==0.00)
			break;
		i=2;
		t=0;
		while(t<c)
		{
			t=t+1.0/i;
			i++;
		}
		printf("%d card(s)\n",i-2);
	}
	return 0;
}