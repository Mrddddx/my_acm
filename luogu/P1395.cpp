#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 5e4 + 5;
struct st
{
    int to, next;
} edge[N << 1];
int head[N];
long long dis;
int cnt = 0;
void init(int x)
{
    for(int i = 0; i <= x; i++){
        edge[i].next = -1;
        head[i] = -1;
    }
    cnt = 0;
}
int n, d[N], ans, num = 0, maxnum = 1e9;
void addedge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u, int fa)
{
    d[u] = 1;
    int tmp = 0;
    for(int i = head[u]; ~i; i = edge[i].next){
        int v = edge[i].to;
        if(v == fa) continue;
        dfs(v, u);
        d[u] += d[v];
        tmp = max(tmp, d[v]);
    }
    tmp = max(tmp, n - d[u]);
    if(tmp < maxnum)
    {
        maxnum = tmp;
        num = 0;
        ans = u;
    }
    else if(tmp == maxnum) ans = min(ans, u);
}
int dfs2(int u, int fa)
{
    int p = 1;
    for(int i = head[u]; ~i; i = edge[i].next){
        int v = edge[i].to;
        if(v == fa) continue;
        p += dfs2(v, u);
    }
    dis += p - 1;
    return p;
}
int main()
{
    cin >> n;
    init(n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    dfs(1, 0);
    dfs2(ans, 0);
        cout << ans << ' ' << dis;
    system("pause");
    return 0;
}