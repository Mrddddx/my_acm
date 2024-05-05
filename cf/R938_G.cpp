#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[110][110];
int b[110][110];
int n, m, maxn;
int GCD(int x, int y){
    //cout << x << ' ' << y << '\n';
    if(x % y == 0) return y;
    else return GCD(y, x % y);
}
inline void D(int x){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] % x) {b[i][j] = 0; continue;}
            else b[i][j] = b[i - 1][j] | b[i][j - 1];
        }
    }
    if(b[n][m]) maxn = max(maxn, x);
} 
void solve(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    int g = GCD(max(a[1][1], a[n][m]), min(a[1][1], a[n][m]));
    maxn = 1;
    b[0][1] = b[1][0] = 1;
    //cout << "GCD = " << g << '\n';
    for(int x = 1; x * x <= g; x++){
        if(g % x == 0) D(x), D(g / x); 
 
        /*for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                cout << b[i][j] << ' ';
            cout << endl;
        }*/

    }
    cout << maxn << endl;
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