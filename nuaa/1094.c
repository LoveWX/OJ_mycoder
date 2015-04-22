#include<stdio.h>
#include<string.h>

#define M 10000

char stuspace[M*20];
char project[100][20];
char *useful[M];
char *useless[M];
char *stu;
int choice[M];
int num[100];
int tsf,tsl,tp;

int main()
{
	char temp[20];
	int i,j,k,flag;
	stu=stuspace;
	while(1)
	{
		gets(temp);
		if(temp[0]=='0')
			break;
		if(temp[0]=='1')
		{
			for(i=0;i<tp;i++)
				num[i]=0;
			for(i=0;i<tsf;i++)
				num[choice[i]]++;
			for(i=0;i<tp;i++)
			{
				k=i;
				flag=num[i];
				for(j=i+1;j<tp;j++)
					if((num[j]>flag)||(num[j]==flag&&strcmp(project[j],project[k])<0))
					{
						k=j;
						flag=num[j];
					}
				if(k!=i)
				{
					flag=num[k];
					num[k]=num[i];
					num[i]=flag;
					strcpy(temp,project[k]);
					strcpy(project[k],project[i]);
					strcpy(project[i],temp);
				}
			}
			for(i=0;i<tp;i++)
				printf("%s %d\n",project[i],num[i]);
			stu=stuspace;
			tp=0;
			tsf=0;
			tsl=0;
			continue;
		}
		if(temp[0]<'a')//是项目名称
		{
			strcpy(project[tp++],temp);
			continue;
		}
		else//是学生姓名
		{
			flag=0;
			for(i=0;i<tsl;i++)
				if(strcmp(useless[i],temp)==0)//检查作废的姓名
				{
					flag=1;
					break;
				}
			if(flag==1)
				continue;

			i=0;
			flag=1;
			while(i<tsf)
			{
				if(strcmp(useful[i],temp)==0)
				{
					flag=0;
					if(choice[i]==tp-1)//单项目多报名
					{
						break;
					}
					else
					{
						useless[tsl++]=useful[i];//作废姓名
						useful[i]=useful[--tsf];
						choice[i]=choice[tsf];
						continue;
					}
				}
				i++;
			}
			if(flag==1)
			{
				strcpy(stu,temp);
				useful[tsf]=stu;
				choice[tsf++]=tp-1;
				stu=stu+strlen(temp)+1;
			}
		}
	}
	return 0;
}