#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 10;
int c[N][N];
int k;
int a[N][N];
void pre(){
    int n, m;
    n = 2000, m = 2000;
    for(int i = 1; i <= n; i++){
        c[i][0] = 1;
    }
    c[0][0] = 1;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= i; j++){
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
            if(c[i][j] == 0) a[i][j] = a[i][j - 1] + 1;
            else a[i][j] = a[i][j - 1];
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= n; i++)
            ans += a[i][min(i, m)];
    cout << ans << '\n';
}
signed main(){
    int T;

    cin >> T >> k;
    pre();
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}