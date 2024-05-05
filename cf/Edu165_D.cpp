#include<bits/stdc++.h>
using namespace std;


const long long N = 2e5 + 5;
struct st{
    long long x, y;
} a[N], take[N];
long long cnt;
void init(long long x){
    for(long long i = 1; i <= x; i++)
        take[i].x = take[i].y = a[i].x = a[i].y = 0;
}
bool cmp(st xx, st yy){
    return xx.y < yy.y;
}
void solve(){
    long long n, k;
    cin >> n >> k;
    cnt = 0;
    for(long long i = 1; i <= n ; i++){
        cin >> a[i].x;
    }
    for(long long i = 1; i <= n ; i++){
        cin >> a[i].y;
        if(a[i].x <= a[i].y)
            take[++cnt].x = a[i].x, take[cnt].y = a[i].y;
    }
    if(cnt <= k) {
        init(n);
        cout << 0 << '\n';
    }
    long long Sa = 0, Sb = 0;
    for(long long i = 1; i <= cnt; i++){
        Sa += take[i].x;
    }
    sort(take + 1, take + cnt + 1, cmp);
    for(long long i = 1; i <= cnt - k; i++)
        Sb += take[i].y;
    init(n);
    cout << cnt << ' ' << Sa << ' ' << Sb << '\n';
    if( Sb - Sa> 0) cout << Sb - Sa << '\n';
    else cout << 0 << '\n';
}

signed main(){
    long long T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}