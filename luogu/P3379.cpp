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
int main()
{
    cin >> n >> m >> root;
    init();
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        addedge(u, v); addedge(v, u);
    }    
    dfs(root, 0);
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
    system("pause");
    return 0;
}
