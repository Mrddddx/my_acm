#include <bits/stdc++.h>
using namespace std;
int n, m;
struct st
{
    int weight;
    int to;
};
int ans;
int rd[1505], cd[1505]; //每个点的入度和出度
vector <st> edge[1505];
queue <int> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({w , v});
        cd[u] ++;
        rd[v] ++;
    }
    q.push(1);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x == n) break;
        
    }
    cout << ans;
    system("pause");
    return 0;
}