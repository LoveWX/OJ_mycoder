#include<stdio.h>
#include<string.h>

char ans[101][200];
char t1[200],t2[200];

void mult(char a[],char b[],char s[])
{
    int i,j,k=0,alen,blen,sum=0,res[65][65]={0},flag=0;
    char result[65];
    alen=strlen(a);blen=strlen(b); 
    for (i=0;i<alen;i++)
    for (j=0;j<blen;j++) res[i][j]=(a[i]-'0')*(b[j]-'0');
    for (i=alen-1;i>=0;i--)
        {
            for (j=blen-1;j>=0;j--) sum=sum+res[i+blen-j-1][j];
            result[k]=sum%10;
            k=k+1;
            sum=sum/10;
        }
    for (i=blen-2;i>=0;i--)
        {
            for (j=0;j<=i;j++) sum=sum+res[i-j][j];
            result[k]=sum%10;
            k=k+1;
            sum=sum/10;
        }
    if (sum!=0) {result[k]=sum;k=k+1;}
    for (i=0;i<k;i++) result[i]+='0';
    for (i=k-1;i>=0;i--) s[i]=result[k-1-i];
    s[k]='\0';
    while(1)
        {
        if (strlen(s)!=strlen(a)&&s[0]=='0') 
            strcpy(s,s+1);
        else
            break;
        }
}

int compare(char a[],char b[])
{
    if(strlen(a)>strlen(b)) return 1;
    if(strlen(a)<strlen(b)) return -1;
    return strcmp(a,b);
}

void div(char a[],char b[],char c[])
{
	while(a[0]=='0')
		a+=1;
	while(b[0]=='0')
		b+=1;
	if(strlen(b)==0)
	{
		c[0]='\0';
		return;
	}
	if(strlen(a)==0)
	{
		c[0]='0';
		c[1]='\0';
		return;
	}
	int len=strlen(a)-strlen(b)+1,start=0;
	char tmp[200];
	if(len<0)
	{
		c[0]='0';
		c[1]='\0';
		return;
	}
	c[len]='\0';
	int i,j;
	for(i=0;i<len;i+=1)
		c[i]='0';
	for(i=0;i<len;i+=1)
	{
		for(j='0';j<='9';j+=1)
		{
			c[i-start]=j;
			mult(b,c,tmp);
			if(compare(tmp,a)>0)
				break;
		}
		if((j=='1')&&(start==i))
		{
			start+=1;
			c[len-start]='\0';
		}
		else
			c[i-start]=j-1;
		
	}
	if(strlen(c)==0)
	{
		c[0]='0';
		c[1]='\0';
	}
}

int main()
{
	int i;
	__int64 a[31]={0,1};
	strcpy(ans[1],"1");
	for(i=2;i<=30;i++)
	{
		a[i]=(4*i-2)*a[i-1]/(i+1);
		sprintf(ans[i],"%I64d",a[i]);
	}
	for(i=31;i<=100;i++)
	{
		sprintf(t1,"%d",i*4-2);
		mult(ans[i-1],t1,t2);
		sprintf(t1,"%d",i+1);
		div(t2,t1,ans[i]);
	}
	while(1)
	{
		scanf("%d",&i);
		if(i==-1)
			break;
		printf("%s\n",ans[i]);
	}
	return 0;
}