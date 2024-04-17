#include<bits/stdc++.h>
using namespace std;
// 倒着来，摧毁<-->重建
// 离线
#define ll long long
const int N = 4e5 + 5; 
int fa[N];

int K[N]; //k[i]表示星球i的时间

int ans[N]; //答案
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
int b[N]; // bi表示i时刻被击落的船
void solve()
{
    int n, m, k;
    cin >> n >> m;
    init(n);
    for(int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v;
    cin >> k;
    // initialize
    int ANS = 0;
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        K[x] = i;
        b[i] = x;
    }
    for(int i = 0; i < n; i++)
        if(!K[i]) ANS++, K[i] = k; //如果每有应该k[i] = 0, 初始数块+1,用b记录它 
    
    for(int i = 1; i <= m; i++)
        a[i].t = min(K[a[i].u], K[a[i].v]);

    sort(a + 1, a + 1 + m, cmp);
    //or(int i = 1; i <= m; i++)
    //    cout << a[i].u << ' ' << a[i].v << ':' << a[i].t << endl;
    ans[k + 1] = ANS;
    a[0].t = k + 1;
    for(int i = 1; i <= m ; i++)
    {
        int j = 0;
        while(a[i].t + j < a[i - 1].t) j++, ANS++;
        int x = father(a[i].u), y = father(a[i].v);
        if( x != y) 
        {
            ANS --; //连通
            fa[x] = y;
        }
        if(a[i].t !=a[i + 1].t) ans[a[i].t] = ANS;
    //    cout << ANS << endl;
    }
    for(int i = 1; i <= k + 1; i++)
    {
        if(ans[i] == 0) ans[i] = ans[i - 1] + 1;
        cout << ans[i] << endl;
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