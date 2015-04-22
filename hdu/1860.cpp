#include<stdio.h>
#include<string.h>

char check[6];
char str[81];
int times[5];

int main()
{
	int i,j,len;
	while(1)
	{
		gets(check);
		if(strcmp(check,"#")==0)
			break;
		len=strlen(check);
		gets(str);
		times[0]=0;
		times[1]=0;
		times[2]=0;
		times[3]=0;
		times[4]=0;
		for(i=strlen(str)-1;i>=0;i--)
		{
			for(j=0;j<len;j++)
				if(str[i]==check[j])
					times[j]++;
		}
		for(i=0;i<len;i++)
			printf("%c %d\n",check[i],times[i]);
	}
	return 0;
}
