#include<stdio.h>
#include<string.h>

int main()
{
	int i,len;
	char str[100],max;
	while(gets(str))
	{
		max=0;
		len=strlen(str);
		for(i=0;i<len;i++)
			if(str[i]>max)
				max=str[i];
		for(i=0;i<len;i++)
		{
			printf("%c",str[i]);
			if(str[i]==max)
				printf("(max)");
		}
		printf("\n");
	}
	return 0;
}