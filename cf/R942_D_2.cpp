#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x, int y){
    if(!(x % y)) return y;
    else return gcd(y, x % y);
}
void solve(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int a = 1; a * a <= n; a++)
        for(int b = 1; b * b <= m; b++){
            if(gcd(max(a, b), min(a, b)) == 1)
                ans += min(n / (a + b) / a, m / (a + b) / b);
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