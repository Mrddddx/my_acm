#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ls (p << 1)
#define rs (p << 1 | 1)
const int N = 1e5 + 5;
ll f[N];
int scr[N];
ll a[N];
int t;
ll ans;
ll pre[N];
ll maxn[N << 2];
void pushup(int p){
    maxn[p] = max(maxn[ls] , maxn[rs]);
}
void build(int p, int pl, int pr){
    if(pl == pr) {maxn[p] = pre[pl]; return;}
    int mid = pl + pr >> 1;
    build(ls, pl, mid); build(rs, mid + 1, pr);
    pushup(p);
}
void update(int x, int p, int pl, int pr, int k){
    if(x == 0) return;
    if(pl == x && pr == x){maxn[p] += k; return;}
    int mid = pl + pr >> 1;
    if(x <= mid) update(x, ls, pl, mid, k);
    else update(x, rs, mid + 1, pr, k);
    pushup(p);
}
ll query(int L, int R, int p, int pl, int pr){
    if(L > R) return 0;
    if(pl >= L && pr <= R){return maxn[p];}
    int mid = pl + pr >> 1;
    ll ans = 0;
    if(L <= mid) ans = max(query(L, R, ls, pl, mid), ans);
    if(R > mid) ans = max(query(L ,R, rs, mid + 1, pr), ans);
    return ans;
}
void solve(){
    ll n;  cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        //cout << pre[i];
    }
    build(1, 1, n);
    for(ll i = n; i >= 1; i--){
        if(a[i] == 0) continue;
        int r = min(n, i + a[i]);
        int L = i + 1;
        f[i] = max(a[i], max(query(L, r, 1, 1, n) - pre[i], f[i + 1]));
        //cout << i << ' ' << f[i] << '\n';
        f[i + 1] = 0;
        update(i, 1, 1, n, f[i]);
    }
    cout << f[1] << '\n';
    f[1] = 0;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}