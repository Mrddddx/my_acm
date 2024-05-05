#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = i; j <= n; j+= i)
            if((j / i + 1) % i == 0) ans ++;
    }
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