#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct edge
{
    int to,w;
};
vector<edge> e[N];//邻接表
int dist[N];//记录距离
void dfs(int u,int father,int d)
{
    dist[u]=d;
    for(int i=0;i<e[u].size();i++)
    {
        if(e[u][i].to!=father)
          dfs(e[u][i].to,u,d+e[u][i].w);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        e[a].push_back({b,w});
        e[b].push_back({a,w});
    }
    dfs(1,-1,0);
    int t=1;
    for(int i=1;i<=n;i++)
        if(dist[i]>dist[t]) t=i;
    dfs(t,-1,0);
    t=1;
    for(int i=1;i<=n;i++)
        if(dist[i]>dist[t]) t=i;
    
    cout<<dist[t]<<endl;
    system("pause");
    return 0;
}