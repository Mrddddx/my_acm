#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5; 
int fa[N];
ll d[N];
void init(int x)
{
    for(int i = 0; i <= x; i++)
        fa[i] = i, d[i] = 0;
}

int father(int x)
{
    if( x != fa[x]) {
        int t = fa[x];
        fa[x] = father(fa[x]);
        d[x] = (d[x] + d[t]) % 3;
    }
    return fa[x];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    init(n);
    int ans = 0; // There is no wrong at first
    for(int i = 1; i <= m; i++)
    {
        int u, v, relation;
        cin >> relation >> u >> v;
        if((relation == 2 && u == v) || u > n || v > n) {ans++;continue;}

        int x = father(u), y = father(v);

        if(x == y){
            if((relation - 1) != (d[u] - d[v] + 3) % 3) ans ++;
        }
        else {
            fa[x] = y;
            d[x] = (d[v] - d[u] + relation - 1) % 3;
            
        }
        //cout << ans;
    }
    cout << ans << endl;
}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

        solve();
    system("pause");
    return 0;
}