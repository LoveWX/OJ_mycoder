#include<iostream>
#include<algorithm>
using namespace std;

struct Score 
{
	char num[7];
	char name[9];
	int mark;
};

struct Score s[100000];

bool cmp1(const Score& a,const Score& b)
{
	return strcmp(a.num,b.num)<0;
}

bool cmp2(const Score& a,const Score& b)
{
	int temp=strcmp(a.name,b.name);
	if(temp==0)
		return strcmp(a.num,b.num)<0;
	return temp<0;
}

bool cmp3(const Score& a,const Score& b)
{
	if(a.mark==b.mark)
		return strcmp(a.num,b.num)<0;
	return a.mark<b.mark;
}

int main()
{
	int n,c,i,tcase=1;
	while(1)
	{
		scanf("%d%d",&n,&c);
		if(n==0&&c==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d",s[i].num,s[i].name,&s[i].mark);
			getchar();	
		}
		if(c==1)
			sort(&s[0],&s[n],cmp1);
		else if(c==2)
			sort(&s[0],&s[n],cmp2);
		else
			sort(&s[0],&s[n],cmp3);
		printf("Case %d:\n",tcase++);
		for(i=0;i<n;i++)
			printf("%s %s %d\n",s[i].num,s[i].name,s[i].mark);
	}
	return 0;
}
