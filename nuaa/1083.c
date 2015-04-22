#include<stdio.h>

int main()
{
	char str[7];
	int d1,d2,i;
	while(scanf("%s",str)!=EOF)
	{
		d1=1;
		for(i=0;str[i]!='\0';i++)
			d1=d1*(str[i]-'A'+1);
		d1%=47;
		scanf("%s",str);
		d2=1;
		for(i=0;str[i]!='\0';i++)
			d2=d2*(str[i]-'A'+1);
		d2%=47;
		if(d1==d2)
			printf("GO\n");
		else
			printf("STAY\n");
	}
	return 0;
}
