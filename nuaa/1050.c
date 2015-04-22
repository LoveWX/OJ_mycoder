#include<stdio.h>

long int a[11]={0,9,81,648,4536,27216,136080,544320,1632960,3265920,3265920};
int p[10]={9,9,8,7,6,5,4,3,2,1};
int used[10];
char s[11];

int main()
{
	long int n,m;
	int i,j,k;
	while(1)
	{
		scanf("%ld",&n);
		if(n==0)
			break;
		if(n<=9)
		{
			printf("%ld\n",n);
			continue;
		}
		for(i=0;i<10;i++)
			used[i]=0;
		n-=9;
		k=2;
		while(n>a[k])
		{
			n-=a[k];
			k++;
		}
		for(j=1,m=1;j<k;j++)
			m*=p[j];
		j=1;
		while(n>m)
		{
			n-=m;
			j++;
		}
		s[0]=j+'0';
		used[j]=1;
		s[k]='\0';
		for(i=1;i<k;i++)
		{
			for(j=i+1,m=1;j<k;j++)
				m*=p[j];
			for(j=0;used[j]==1;j++);
			while(n>m)
			{
				n-=m;
				for(j++;used[j]==1;j++);
			}
			s[i]=j+'0';
			used[j]=1;
		}
		printf("%s\n",s);
	}
	return 0;
}