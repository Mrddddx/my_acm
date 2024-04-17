#include<bits/stdc++.h>
using namespace std;
int fa[1010];
void init(int x)
{
    for(int i = 1; i <= x; i++)
        fa[i] = i;
}

int father(int x)
{
    if( x != fa[x]) return fa[x] = father(fa[x]);
    return fa[x];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    init(n);
    int ans = n; // There are n tables if they dont kown each other
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        int x = father(u), y = father(v);
        if(x != y) ans--, fa[y] = fa[x]; // new friends , less tables;
    }
    cout << ans << endl;
}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr)
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    system("pause");
    return 0;
}