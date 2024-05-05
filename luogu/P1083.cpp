#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m;
int a[N], d[N];
struct st{
    int d, b, e;
} q[N];
bool check(int x){
    //cout << x;
    for(int i = 1; i < x; i++){
        d[q[i].b] += q[i].d;
        d[q[i].e + 1] -= q[i].d;
    }
    int now = 0, f = 0;
    for(int i = 1; i <= n ;i ++){
        now += d[i];
        //cout << now << ' ';
        if(now > a[i]) {f = 1; break;}
    }
    //cout << '\n';
    for(int i = 1; i < x; i++){
        d[q[i].b] -= q[i].d;
        d[q[i].e + 1] += q[i].d;
    }
    if(f) return 1;
    return 0;
}
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> q[i].d >> q[i].b >> q[i].e;
    }
    int L = 1, R = m + 1;

    while(L < R){
        int mid = L + R >> 1;
        if(check(mid)) R = mid;
        else L = mid + 1;
    }
    if(L > m) cout << 0;
    else  cout << "-1\n" <<L - 1;
    system("pause");
    return 0;
}