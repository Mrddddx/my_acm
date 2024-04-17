#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ans;
vector<int> e[N];//邻接表
int dist;
void dfs(int u,int father,int d)
{
    if(d>ans) ans=d;
    if(d>dist) return ;
    for(int i=0;i<e[u].size();i++)
    {
        if(e[u][i]!=father)
          dfs(e[u][i],u,d+1);
    }
}

int main()
{
    int n;
    cin>>n>>dist;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1,-1,0);
    cout<<ans;
    system("pause");
    return 0;
}