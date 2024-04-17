#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long  a[20000086],t1[20000086],t2[20000086];
int n;
int n1,n2;
long long ans;
void _in()
{
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[x]++;
    }
}
void tsort()
{
    for(int i=1;i<=100010;i++)
    {
        while (a[i])
        {
            a[i]--;
            t1[++n1]=i;
        }
    }
}

int main()
{  
    memset(t2,127,sizeof(t2));
    memset(t1,127,sizeof(t2));
    _in();
    tsort();
    int i=1,j=1,k=1;

    while(k<n)
    {
        long long  w,m;
        if(t1[i]<t2[j])
        {
            w=t1[i];
            i++;
        }
        else 
        {
            w=t2[j];
            j++;
        }        
        if(t1[i]<t2[j])
        {
            m=t1[i];
            i++;
        }
        else 
        {
            m=t2[j];
            j++;
        }
        ans+=m+w;
        t2[++n2]=m+w;
        k++;
        //printf("%d %d %d\n",w,m,ans);
    }
    /*for (int i = 1; i <=n; i++)
    {
        printf("%d ",t2[i]);
    }*/

    printf("%d",ans);
    system("pause");
    return 0;
}