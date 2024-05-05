#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct Edge
{
    int to, next;
} edge[N << 1];
int head[N << 1], cnt;
int n, root, m;
int deep[N], fa[N][20];
int D[N];
void init()
{
    for(int i = 0; i <= (n << 1); i++)
        edge[cnt].next = head[i] = -1;
    cnt = 0;
}
void addedge(int u, int v)
{
    edge[cnt].to = v; 
    edge[cnt].next = head[u];
    head[u] = cnt ++;
}
void dfs(int x, int father)
{
    deep[x] = deep[father] + 1;
    fa[x][0] = father;
    for(int i = 1; (1 << i) <= deep[x]; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for(int i = head[x]; ~i; i = edge[i].next)
        if(edge[i].to != father)
            dfs(edge[i].to, x);
}
int LCA(int x, int y)
{
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 19; i >= 0; i--)
        if(deep[x] - (1 << i) >= deep[y])
            x = fa[x][i];
        if(x == y) return x;
    for(int i = 19; i >= 0; i--)
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i]; y = fa[y][i];
        }
    return fa[x][0];
}
int ans;
void dfs2(int u, int fath)
{
    for(int i = head[u]; ~i; i = edge[i].next)
    {
        int e = edge[i].to;
        if(e == fath) continue;
        dfs2(e, u);
        D[u] += D[e];
    }
    ans = max(D[u], ans);
}
int main()
{
    cin >> n >> m;
    init();
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        addedge(u, v); addedge(v, u);
    }    
    dfs(1, 0);
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        int lca = LCA(u, v);
        D[u] ++; D[v]++;
        D[lca]--; D[fa[lca][0]]--;
    }
    dfs2(1, 0);
    cout << ans;
    system("pause");
    return 0;
}
