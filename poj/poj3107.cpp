#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 5e4 + 5;
struct st
{
    int to, next;
} edge[N << 1];
int head[N];
int cnt = 0;
void init(int x)
{
    for(int i = 0; i <= x; i++){
        edge[i].next = -1;
        head[i] = -1;
    }
    cnt = 0;
}
int n, d[N], ans[N], num = 0, maxnum = 1e9;
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
        ans[++num] = u;
    }
    else if(tmp == maxnum) ans[++num] = u;
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
    sort(ans + 1, ans + 1 + num);
    for(int i = 1; i <= num; i++)
        cout << ans[i] << ' ';
    //system("pause");
    return 0;
}