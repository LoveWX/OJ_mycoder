#include<stdio.h>

int main()
{
	int prime[10]={1,1,2,6,24,120,720,5040,40320,362880};
	int used[11];
	int n,i,len,p;
	long int k;
	char ns[10];
	while(scanf("%d%ld",&n,&k)!=EOF)
	{
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		for(i=1;i<=n;i++)
			used[i]=0;
		k++;
		k%=prime[n];
		if(k==0)
			k=prime[n];
		len=n;
		n--;
		i=1;
		p=0;
		while(k>0)
		{
			if(k>prime[n])
			{
				k-=prime[n];
				for(i++;used[i]==1;i++);
			}
			else if(k<prime[n])
			{
				ns[p++]=i+'0';
				n--;
				used[i]=1;
				for(i=1;used[i]==1;i++);
			}
			else
			{
				ns[p++]=i+'0';
				used[i]=1;
				for(i=len;used[i]==1;i--);
				while(p<len)
				{
					if(used[i]!=1)
						ns[p++]=i+'0';
					i--;
				}
				k=-1;
			}
		}
		ns[len]='\0';
		printf("%s\n",ns);
	}
	return 0;
}