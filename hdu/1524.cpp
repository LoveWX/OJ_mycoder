#include<stdio.h>
#define N 1000
typedef struct v
{
    int vex;
    v* next;
}VEX;

typedef struct
{
    int num;
    v* next;
}HEAD;

int g[N],queue[N];
HEAD p[N];
int n;

int findg(int i)
{
	bool f[N]={0};
	VEX *vt=p[i].next;
	while(vt!=NULL)
	{
		f[g[vt->vex]]=1;
		vt=vt->next;
	}
	for(i=0;i<n;i++)
		if(f[i]==0)
			return i;
}

int main()
{
	VEX *vt;
	int i,j,b,t;
	while(scanf("%d",&n)!=EOF)
	{
		b=0;
		t=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			p[i].num=j;
			p[i].next=NULL;
			while(j-->0)
			{
				vt=new VEX;
				scanf("%d",&(vt->vex));
				vt->next=p[i].next;
				p[i].next=vt;
			}
		}
		j=n;
		while(j>0)
		{
			for(i=0;i<n;i++)
				if(p[i].num==0)
				{
					j--;
					queue[t++]=i;
					p[i].num--;
					g[i]=findg(i);
				}
			while(b<t)
            {
                for(i=0;i<n;i++)
                {
                    if(p[i].num<=0)
                        continue;
                    vt=p[i].next;
                    while(vt!=NULL)
                    {
                        if(vt->vex==queue[b])
                            p[i].num--;
                        vt=vt->next;
                    }
                }
                b++;
            }
		}
		while(1)
		{
			scanf("%d",&b);
			if(b==0)
				break;
			t=0;
			while(b-->0)
			{
				scanf("%d",&j);
				t^=g[j];
			}
			if(t>0)
				printf("WIN\n");
			else
				printf("LOSE\n");
		}
	}
	return 0;
}