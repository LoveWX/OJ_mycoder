#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct Student
{
	char name[25];
	int score;
};

Student s[1000];

bool cmp(const Student& a,const Student& b)
{
	if(a.score==b.score)
		return strcmp(a.name,b.name)<0;
	return a.score>b.score;
}

int main()
{
	int i,j,n,m,g,score,num;
	int mark[11];
	char tempname[25];
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d%d",&m,&g);
		for(i=1;i<=m;i++)
			scanf("%d",&mark[i]);
		getchar();
		num=0;
		while(n-->0)
		{
			scanf("%s%d",tempname,&i);
			score=0;
			while(i-->0)
			{
				scanf("%d",&j);
				score+=mark[j];
			}
			getchar();
			if(score>=g)
			{
				strcpy(s[num].name,tempname);
				s[num++].score=score;
			}
		}
		printf("%d\n",num);
		sort(&s[0],&s[num],cmp);
		for(i=0;i<num;i++)
		{
			printf("%s %d\n",s[i].name,s[i].score);
		}
	}
	return 0;
}