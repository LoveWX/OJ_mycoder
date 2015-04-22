#include<stdio.h>
#include<string.h>

char t1[216],t2[216],t3[216];

void mult(char a[],char b[],char s[])
{
    int i,j,k=0,alen,blen,sum=0,res[216][216]={0},flag=0;
    char result[216];
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
	int i,j;
	__int64 a[21]={0,1};
	for(i=2;i<=13;i++)
		a[i]=a[i-1]*(i+i)*(i+i-1)/(i+1);
	while(1)
	{
		scanf("%d",&i);
		if(i==0)
			break;
		if(i<=13)
		{
			printf("%I64d\n",a[i]);
			continue;
		}
		sprintf(t1,"%d",i+2);
		for(j=i+3;j<=i+i;j++)
		{
			sprintf(t2,"%d",j);
			mult(t1,t2,t3);
			strcpy(t1,t3);
		}
		printf("%s\n",t1);
	}
	return 0;
}