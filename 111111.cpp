#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int r=5,c=7;
int a[5][7],px[10],py[10],pz[10],n,cnt[11],tot;
bool clr()
{
    int i,j,k;
    bool flag=0,out[5][7]={0};
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
          if (!a[i][j])
            for (k=j+1;k<c;k++)
              if (a[i][k])
              {
                swap(a[i][j],a[i][k]);
                break;
              }
    }
    for (i=0;i<r;i++)
      for (j=0;j<c;j++)
      {
        if (i<=r-3&&a[i][j]&&a[i][j]==a[i+1][j]&&a[i+1][j]==a[i+2][j])
          out[i][j]=out[i+1][j]=out[i+2][j]=1,flag=1;
        if (j<=c-3&&a[i][j]&&a[i][j]==a[i][j+1]&&a[i][j+1]==a[i][j+2])
          out[i][j]=out[i][j+1]=out[i][j+2]=1,flag=1;
      }
    for (i=0;i<r;i++)
      for (j=0;j<c;j++)
        if (out[i][j])
        {
            tot--;
            cnt[a[i][j]]--;
            a[i][j]=0;
        }
    return flag;
}
bool dfs(int s)
{
    int i,j;
    for (i=1;i<=10;i++)
      if (cnt[i]&&cnt[i]<3) return 0;
    if (s==n+1) return !tot;
    int t1[5][7],t2[11],t3=tot;
    memcpy(t1,a,sizeof(t1));
    memcpy(t2,cnt,sizeof(cnt));
    for (i=0;i<r-1;i++)
      for (j=0;j<c;j++)
        if (a[i][j]!=a[i+1][j])
        {
            swap(a[i][j],a[i+1][j]);
            if (a[i+1][j])
            {
                px[s]=i;
                py[s]=j;
                pz[s]=1;
            }
            else
            {
                px[s]=i+1;
                py[s]=j;
                pz[s]=-1;
            }
            while (clr());
            if (dfs(s+1)) return 1;
            memcpy(a,t1,sizeof(a));
            memcpy(cnt,t2,sizeof(t2));
            tot=t3;
        }
    return 0;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for (i=0;i<r;i++)
      for (j=0;;j++)
      {
        scanf("%d",&a[i][j]);
        if (a[i][j])
        {
            tot++;
            cnt[a[i][j]]++;
        }
        else break;
      }
    if (dfs(1))
      for (i=1;i<=n;i++)
        printf("%d %d %d\n",px[i],py[i],pz[i]);
    else
      printf("-1\n");
}