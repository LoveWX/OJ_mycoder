#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,n;
	char num[100];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n-->0)
		{
			gets(num);
			i=0;
			j=strlen(num)-1;
			while(i<j)
			{
				if(num[i]!=num[j])
				{
					printf("no\n");
					break;
				}
				i++;
				j--;
			}
			if(i>=j)
				printf("yes\n");
		}
	}
	return 0;
}