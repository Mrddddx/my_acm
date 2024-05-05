#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
char a[N];
void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 'U') cnt++;
    }
    if(cnt & 1) cout << "YES\n";
    else cout << "NO\n";

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