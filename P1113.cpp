#include <bits/stdc++.h>
using namespace std;
int ans;
int n;
vector <int> edge[10010];
int len[10010];
int f[10010];
int dfs(int x)
{
    if(f[x]) return f[x];
    int sz = edge[x].size();
    for(int i = 0; i < sz; i++)
        f[x] = max(f[x] , dfs(edge[x][i])); 
    f[x] += len[x];
    return f[x];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        int x;
        cin >> x;
        cin >> len[x];
        cin >> t;
        while (t)
        {
            edge[t].push_back(x);
            cin >> t;
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans , dfs(i));

    cout << ans;
    system("pause");
    return 0;
}