#include<stdio.h>

int main()
{
	int h[20],next[20],pre[20],i,j,k,len=0,flag,m1,m=1;
	while(scanf("%d",&h[len])!=EOF)
	{
		len++;
	}
	next[0]=1;
	pre[0]=-1;
	for(i=1;i<len;i++)
	{
		flag=0;
		k=0;
		for(j=0;j<i;j++)
			if(h[j]>=h[i]&&next[j]>=next[k])
			{
				flag=1;
				k=j;
			}
		if(flag==1)
		{
			next[i]=next[k]+1;
			pre[i]=k;
		}
		else
		{
			next[i]=1;
			pre[i]=-1;
		}
	}
	len--;
	k=0;
	for(i=1;i<=len;i++)
		if(next[i]>next[k])
			k=i;
	m1=next[k];
	while(1)
	{
		k=0;
		for(i=1;i<=len;i++)
			if(next[i]>next[k]||(next[i]==next[k]&&h[i]<h[k]))
				k=i;
		i=k;
		while(i>-1)
		{
			h[i]=-2;
			i=pre[i];
		}
		i=0;
		j=0;
		while(i<=len)
		{
			if(h[i]!=-2)
				h[j++]=h[i++];
			else
				i++;
		}
		len=j;
		if(len<=0)
			break;
		for(i=1;i<len;i++)
		{
			flag=0;
			k=0;
			for(j=0;j<i;j++)
				if(h[j]>=h[i]&&next[j]>=next[k])
				{
					flag=1;
					k=j;
				}
			if(flag==1)
			{
				next[i]=next[k]+1;
				pre[i]=k;
			}
			else
			{
				next[i]=1;
				pre[i]=-1;
			}
		}
		m++;
		len--;
	}
	printf("%d\n%d\n",m1,m);
	return 0;
}