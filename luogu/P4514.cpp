#include<bits/stdc++.h>
using namespace std;
const int N=2222;
int n,m;
int t1[N][N],t2[N][N],t3[N][N],t4[N][N];
#define lowbit(x) ((x)&(-x))
void updata(int x,int y,int d)
{
  for(int i=x;i<=n;i+=lowbit(i))
    for(int j=y;j<=m;j+=lowbit(j))
    {
       t1[i][j]+=d;t2[i][j]+=d*x;
       t3[i][j]+=d*y;t4[i][j]+=d*x*y;
    }
}
int sum(int x,int y)
{
  int ans=0;
  for(int i=x;i>0;i-=lowbit(i))
    for(int j=y;j>0;j-=lowbit(j))
      ans+=(x+1)*(y+1)*t1[i][j]-(y+1)*t2[i][j]-(x+1)*t3[i][j]+t4[i][j];
    return ans;
} 
int main()
{
  char ch[2],x;
  int a,b,c,d,delta;
  scanf("%s",ch);
  cin>>n>>m;
  while(scanf("%s",ch)!=EOF)
  {
    cin>>a>>b>>c>>d;
    if(ch[0]=='L') 
    { 
      cin>>delta;
      updata(a,b,delta);
      updata(c+1,d+1,delta);
      updata(a,d+1,-delta);
      updata(c+1,b,-delta);
    }
    else cout<<sum(c,d)+sum(a-1,b-1)-sum(a-1,d)-sum(c,b-1)<<endl;
  }
  return 0;
}