#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y){
    return !(x % y) ? y : gcd(y, x % y);
}
void solve(){
    int n ;
    cin >> n;
    if(n == 1) cout << 1 << '\n';
    else cout << n * (n - 1) << '\n';
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