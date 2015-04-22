#include<stdio.h>

int pos[81];
int pos1[81];
int pos3[81];
int pos2[81];
int visit[81];
int ans[81];
char str[81];

int main()
{
	int n,t,i,step;
	long m;
	while(1)
	{
		scanf("%d%ld",&n,&m);
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d",&visit[i]);
		for(i=1;i<=n;i++)
		{
			pos[visit[i]]=i;
			visit[i]=0;
			pos1[i]=i;
			pos3[i]=i;
		}
		getchar();
		str[0]=' ';
		gets(str+1);
		t=n;
		step=1;
		while(t>0)
		{
			for(i=1;i<=n;i++)
			{
				pos2[i]=pos3[pos[i]];
				if(visit[i]==0&&pos2[i]==pos1[i])
				{
					visit[i]=1;
					ans[i]=step;
					t--;
				}
			}
			for(i=1;i<=n;i++)
				pos3[i]=pos2[i];
			step++;
		}
		step--;
		for(i=1;i<=n;i++)
			ans[i]=m%ans[i];
		for(step=1;step<=n;step++)
		{
			t=step;
			for(i=0;i<ans[step];i++)
				t=pos[t];
			printf("%c",str[t]);
		}
		printf("\n");
	}
	return 0;
}