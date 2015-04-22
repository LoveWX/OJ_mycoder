#include<stdio.h>
#include<string.h>
#include<malloc.h>

char fac[101][400];
char ans[101][101][400];

void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    char *c;
    if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;
    c=(char *) malloc(l*sizeof(char));
    i=strlen(a)-1;
    j=strlen(b)-1;
    k=0;up=0;
    while(i>=0||j>=0)
        {
            if(i<0) x='0'; else x=a[i];
            if(j<0) y='0'; else y=b[j];
            z=x-'0'+y-'0';
            if(up) z+=1;
            if(z>9) {up=1;z%=10;} else up=0;
            c[k++]=z+'0';
            i--;j--;
        }
    if(up) c[k++]='1';
    i=0;
    c[k]='\0';
    for(k-=1;k>=0;k--)
        back[i++]=c[k];
    back[i]='\0';
}

void mult(char a[],char b[],char s[])
{
    int i,j,k=0,alen,blen,sum=0,res[400][400]={0},flag=0;
    char result[400];
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

int main()
{
	int i,j,c=1;
	__int64 a[101][101]={0};
	char temp1[400],temp2[400];
	a[0][0]=1;
	a[0][1]=1;
	sprintf(fac[0],"%I64d",a[0][0]);
	sprintf(fac[1],"%I64d",a[0][1]);
	for(i=2;i<=20;i++)
	{
		a[0][i]=a[0][i-1]*i;
		sprintf(fac[i],"%I64d",a[0][i]);
	}
	for(i=0;i<=20;i++)
		for(j=0;j<200;j++)
			a[i][j]=0;
	sprintf(ans[0][0],"1");
	for(i=21;i<=100;i++)
	{
		sprintf(temp1,"%d",i);
		mult(fac[i-1],temp1,fac[i]);
	}
	for(i=1;i<=20;i++)
	{
		a[i][0]=1;
		sprintf(ans[i][0],"1");
		for(j=1;j<=i;j++)
		{
			a[i][j]=a[i-1][j]+a[i][j-1];
			sprintf(ans[i][j],"%I64d",a[i][j]);
		}
	}
	for(i=21;i<=100;i++)
	{
		sprintf(ans[i][0],"1");
		for(j=1;j<=i;j++)
			add(ans[i-1][j],ans[i][j-1],ans[i][j]);
	}
	while(1)
	{
		scanf("%d%d",&i,&j);
		if(i==0&&j==0)
			break;
        if(i<j) 
        {
            printf("Test #%d:\n0\n",c++);
            continue;
        }
        if(j==0) 
        {
            printf("Test #%d:\n%s\n",c++,fac[i]);
            continue;
        }
		mult(fac[i],fac[j],temp1);
		mult(ans[i][j],temp1,temp2);
		printf("Test #%d:\n%s\n",c++,temp2);
	}
	return 0;
}