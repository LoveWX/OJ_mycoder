#include<iostream>
using namespace std;
#define N 10001
#define M 20001

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

int set[N],nout[N],a[M],b[M];
HEAD p[N];

int findr(int x)
{
    while(x!=set[x])
        x=set[x];
    return x;
}

void merge(int a,int b)
{
    int ra=findr(a),rb=findr(b);
    if(ra<rb)
        set[rb]=ra;
    else
        set[ra]=rb;
}

int main()
{
    VEX *vt;
    int i,j,m,tc,n;
    bool isuncertain,isconflict;
    char oper;
    while(scanf("%d%d",&j,&m)!=EOF)
    {
        if(m==0)
        {
            if(j<=1)
                printf("OK\n");
            else
                printf("UNCERTAIN\n");
            continue;
        }
        for(i=0;i<j;i++)
        {
            set[i]=i;
            p[i].num=0;
            p[i].next=NULL;
        }
        tc=0;
        while(m-->0)
        {
            scanf("%d %c %d",&a[tc],&oper,&b[tc]);
            if(oper=='=')
                merge(a[tc],b[tc]);
            else
            {
                if(oper=='<')
                {
                    n=a[tc];
                    a[tc]=b[tc];
                    b[tc]=n;
                }
                tc++;
            }
        }
        m=0;
        for(i=0;i<j;i++)
            if(i==set[i])
                nout[i]=m++;
            else
                nout[i]=nout[findr(i)];
        isconflict=false;
        for(i=0;i<tc;i++)
        {
            n=nout[a[i]];
            if(n==nout[b[i]])
            {
                printf("CONFLICT\n");
                isconflict=true;
                break;
            }
            j=1;
            vt=p[n].next;
            while(vt!=NULL)
            {
                if(vt->vex==nout[b[i]])
                {
                    j=0;
                    break;
                }
                vt=vt->next;
            }
            if(j==0)
                continue;
            vt=new VEX;
            vt->vex=nout[b[i]];
            vt->next=p[n].next;
            p[n].next=vt;
            p[n].num++;
        }
        if(isconflict)
        {
            for(i=0;i<n;i++)
            {
                vt=p[i].next;
                while(vt!=NULL)
                {
                    p[i].next=vt->next;
                    delete vt;
                    vt=p[i].next;
                }
            }
            continue;
        }
        j=0;
        tc=0;
        n=m;
        isuncertain=false;
        while(m>0)
        {
            for(i=0;i<n;i++)
                if(p[i].num==0)
                {
                    m--;
                    set[tc++]=i;
                    p[i].num--;
                }
            if(j>=tc)
            {
                isconflict=true;
                break;
            }
            if(tc-j>1)
                isuncertain=true;
            while(j<tc)
            {
                for(i=0;i<n;i++)
                {
                    if(p[i].num<=0)
                        continue;
                    vt=p[i].next;
                    while(vt!=NULL)
                    {
                        if(vt->vex==set[j])
                            p[i].num--;
                        vt=vt->next;
                    }
                }
                j++;
            }
        }
        if(isconflict)
            printf("CONFLICT\n");
        else if(isuncertain)
            printf("UNCERTAIN\n");
        else
            printf("OK\n");
        for(i=0;i<n;i++)
        {
            vt=p[i].next;
            while(vt!=NULL)
            {
                p[i].next=vt->next;
                delete vt;
                vt=p[i].next;
            }
        }
    }
    return 0;
}