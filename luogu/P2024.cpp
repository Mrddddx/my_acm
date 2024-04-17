#include<bits/stdc++.h>
using namespace std;
int N,K;
int s[50101];
int d[50101];

void init_set(int n)
{
  for(int i=1;i<=n;i++)
  {s[i]=i;d[i]=0; }
}

int ans;

int find_set(int x)
{
  if(x!=s[x])
  {
    int t=s[x];
    s[x] = find_set(s[x]);
    d[x] = (d[x]+d[t])%3;
  }
  return s[x];
}

void merge_set(int x,int y,int r)
{
  int rx=find_set(x),ry=find_set(y);
  if(rx==ry)
  {
    if((r-1)!=((d[x]-d[y]+3)%3)) ans++;
  }
  else {s[rx]=ry;d[rx]=(d[y]-d[x]+r-1)%3;}
}


int main()
{
  cin>>N>>K;
  init_set(N);
  for(int k=1;k<=K;k++)
  {
    int r,x,y;
    cin>>r>>x>>y;
    if(x>N||y>N||(r==2&&x==y)) ans++;
    else merge_set(x,y,r);
  }
  cout<<ans;
  system("pause");
  return 0;
}
    