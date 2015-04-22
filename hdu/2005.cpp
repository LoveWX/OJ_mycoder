#include<stdio.h>

int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int y,m,d;
	while(scanf("%d/%d/%d",&y,&m,&d)!=EOF)
	{
		if(m>=3&&((y%4==0&&y%100!=0)||y%400==0))
			d++;
		for(y=1;y<m;y++)
			d+=day[y];
		printf("%d\n",d);
	}
	return 0;
}