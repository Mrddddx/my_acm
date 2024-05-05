#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct Edge
{
    int to, next;
} edge[N << 1];
int head[N << 1], cnt;
int deep[N];
int siz[N], son[N], top[N], fa[N];
void init()
{
    for(int i = 0; i < N << 1; i++)
        edge[i].next = head[i] = -1;
    cnt = 0;
}
void addedge(int u, int v){
    edge[cnt].to = v;   edge[cnt].next = head[u];   head[u] = cnt ++;
}
void dfs1(int x, int father){
    deep[x] = deep[father] + 1;
    fa[x] = father;
    siz[x] = 1;
    for(int i = head[x]; ~i; i = edge[i].next){
        int y = edge[i].to;
        if(y == father) continue;
        //fa[y] = x;
        dfs1(y, x);
        siz[x] += siz[y];
        if(!son[x] || siz[son[x]] < siz[y])
            son[x] = y;
    }
}

void dfs2(int x, int topx)
{
    top[x] = topx;
    if(!son[x]) return;
    dfs2(son[x], topx);
    for(int i = head[x]; ~i; i = edge[i].next){
        int y = edge[i].to;
        if(y == fa[x] || y == son[x]) continue;
        dfs2(y, y);
    }
}
int LCA(int x, int y){
    while(top[x] != top[y]){
        if(deep[top[x]] < deep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
}
int main()
{
    init();
    int n, m, root;     cin >> n >> m >> root;
    for(int i = 1; i < n; i++){
        int u, v;    cin >> u >> v;
        addedge(u, v);   addedge(v, u);
    }
    dfs1(root, 0);
    dfs2(root, root);
    while(m--){
        int x, y;    cin >> x >> y;
        cout << LCA(x, y) << '\n';
    }
    system("pause");
    return 0;
}