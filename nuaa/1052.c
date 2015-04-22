#include<stdio.h>

char dir[1000][8];
char word[8];
int numofch[26];
int tnch[26];
int ne,tne;

int main()
{
	char *tch;
	int n,i,j,flag,t,ans;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		getchar();
		for(i=0;i<n;i++)
			gets(dir[i]);
		gets(word);
		ne=0;
		ans=0;
		for(i=0;i<26;i++)
			numofch[i]=0;
		for(i=0;word[i]!='\0';i++)
		{
			if(word[i]=='_')
				ne++;
			else
				numofch[word[i]-'A']++;
		}
		tne=ne;
		for(i=0;i<26;i++)
			tnch[i]=numofch[i];
		for(i=0;i<n;i++)
		{
			flag=1;
			tch=dir[i];
			for(j=0;tch[j]!='\0';j++)
			{
				t=tch[j]-'A';
				if(numofch[t]<=0)
				{
					if(ne>0)
						ne--;
					else
					{
						flag=0;
						break;
					}
				}
				else
					numofch[t]--;
			}
			ans+=flag;
			for(j--;j>=0;j--)
			{
				t=tch[j]-'A';
				numofch[t]=tnch[t];
			}
			ne=tne;
		}
		printf("%d\n",ans);
	}
	return 0;
}