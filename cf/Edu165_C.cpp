#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N];
int d[N];
void solve(){
    int n, y, k;
    cin >> n >> k >> y;
    int in_y = y;
    int ans = 0;
    for(int i = 1; i <= k; i++){
        cin >> a[i]; 
    }
    sort(a + 1, a + 1 + k);
    
    d[1] = n + a[1] - a[k] - 1;
    
    for(int i = 2; i <= k; i++){
        d[i] = a[i] - a[i - 1] - 1;
    }
    sort(d + 1, d + 1 + k);
    for(int i = 1; i <= k; i++){
        //cout << d[i] << '\n';
        if(d[i] & 1)
            if(y >= d[i] >> 1) y -= d[i] >> 1, ans += (d[i] >> 1) + 1;
            else  ans += y, y = 0;
    }
    for(int i = 1; i <= k; i++){
        if(d[i] & 1) continue;
        if(y >= d[i] >> 1) y -= d[i] >> 1, ans += d[i] >> 1;
        else  ans += y, y = 0;
        //cout << ans << ' ';
    }
    ans += (in_y - y) + k - 2;
    cout << ans << '\n';
}

signed main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}