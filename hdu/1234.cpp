#include<stdio.h>
#include<string.h>

int change(char *t)
{
	return (t[0]-'0')*100000+(t[1]-'0')*10000+(t[3]-'0')*1000+(t[4]-'0')*100+(t[6]-'0')*10+(t[7]-'0');
}

int main()
{
	int times,n,firsttime,lasttime,t1,t2;
	char name[16],firstname[16],lastname[16],time1[10],time2[10];
	scanf("%d",&times);
	while (times-->0)
	{
		scanf("%d",&n);
		getchar();
		firsttime=240000;
		lasttime=-1;
		while(n-->0)
		{
			scanf("%s%s%s",name,time1,time2);
			getchar();
			t1=change(time1);
			t2=change(time2);
			if(t1<firsttime)
			{
				firsttime=t1;
				strcpy(firstname,name);
			}
			if(t2>lasttime)
			{
				lasttime=t2;
				strcpy(lastname,name);
			}
		}
		printf("%s %s\n",firstname,lastname);
	}
	return 0;
}
