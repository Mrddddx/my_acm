#include<bits/stdc++.h>
using namespace std;
int n;
int a[110];
bool b[110];
int D[110];//木棍的可能长度
int sum;
int flag;
int t;
int ned;
int ans;
bool cmp(int x,int y)
{
    return x>y;
}

bool dfs(int now,int num,int R)
{
    //cout<<now<<' '<<num<<' '<<R<<endl;
    if(now==ned) return 1;
    if(R==0) if(dfs(now+1,1,ans)) return 1;
    for(int j=num;j<=n;j++)
    {
        if(b[j]==1) continue;
        
        if(a[j]<=R)
        {
            b[j]=1;
            if(dfs(now,j+1,R-a[j])) return 1;
            b[j]=0;
            if(R==ans||R==a[j]) break;
            while(a[j]==a[j+1]) ++j;
        }
    }
    return 0;
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++) 
  {
    scanf("%d",&a[i]);
    sum+=a[i];
  }
  sort(a+1,a+1+n,cmp);

  for(int i=a[1];i<=sum;i++)
    if(sum%i==0) D[++t]=i;
  for(int k=1;k<=t;k++)
  {
    ned=sum/D[k];
    ans=D[k];
    if(dfs(0,1,D[k])) 
    {
        cout<<D[k];
        //system("pause");
        return 0;
    }
  }
  //system("pause");
  //cout<<"NO";
  return 0;
}
    