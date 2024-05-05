#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[110][110];
int b[110][110];
int gcd(int x, int y){
    if(x % y == 0) return y;
    else return (y, x % y);
}
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    int g = gcd(max(a[1][1], a[n][m]), min(a[1][1], a[n][m]));
    int maxn = 1;
    b[0][1] = b[1][0] = 1;
    for(int x = sqrt(g); x >= 2; x--){
        if(g % x) continue;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i][j] % x) {b[i][j] = 0; continue;}
                else b[i][j] = b[i - 1][j] | b[i][j - 1];
            }
        } 
        if(b[n][m]) {maxn = x; break;}
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] % g != 0) b[i][j] = 0; 
            else b[i][j] = b[i - 1][j] ^ b[i][j - 1];
        }
    }
    for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                cout << b[i][j] << ' ';
            cout << endl;
        }
    if(b[n][m]) maxn = g;
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