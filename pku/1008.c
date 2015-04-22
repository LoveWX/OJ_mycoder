#include<stdio.h>
#include<string.h>
#define SIZE 20

char * haab[SIZE-1]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char * tzolkin[SIZE]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int m;
int d;
int y;

void convert()
{
	long int days;
	days=y*365+m*20+d+1;
	y=days/260;
	days=days%260;
	if(days==0)
		y--;
	d=days%13;
	if (d==0)
		d=13;
	m=days%20;
	if (m==0)
		m=20;
}

int main()
{
	int a,i,j;
	char month[8];
	while(scanf("%d",&a)!=EOF)
	{
		printf("%d\n",a);
		for(i=0;i<a;i++)
		{
			scanf("%d",&d);
			getchar();
			getchar();
			scanf("%s",month);
			for(j=0;j<SIZE;j++)
				if(strcmp(month,haab[j])==0)
				{
					m=j;
					break;
				}
			scanf("%d",&y);
			
			convert();
			printf("%d %s %d\n",d,tzolkin[m-1],y);
		}
	}

	return 0;
}