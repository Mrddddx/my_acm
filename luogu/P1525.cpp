#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5; 
int fa[N];
int d[N];
int H[N];
struct st{
    int u, v, t;
} a[N];
void init(int x)
{
    for(int i = 0; i <= x; i++)
        fa[i] = i;
}

int father(int x)
{
    if( x != fa[x])  return fa[x] = father(fa[x]);
    return fa[x];
}

bool cmp(st x, st y)
{
    return x.t > y.t;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    init(n);
    int ans = n; // All the villege are devided
    for(int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].t;
    sort(a + 1, a + 1 + m, cmp);
    for(int i = 1; i <= m + 1; i++)
    {

        int x = father(a[i].u), y = father(a[i].v);
        if( x == y) 
        {
            cout << a[i].t;
            return;
        }
        if(!H[a[i].u]) H[a[i].u] = a[i].v;
            else 
            {
                int u = father(H[a[i].u]), v = father(a[i].v);
                fa[u] = v;
            }
        if(!H[a[i].v]) H[a[i].v] = a[i].u;
            else 
            {
                int u = father(H[a[i].v]), v = father(a[i].u);
                fa[u] = v;
            }
    }

    return ;
}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

        solve();
    system("pause");
    return 0;
}