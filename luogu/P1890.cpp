#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 10;
int f[N][N];
int a[N];
int gcd(int x, int y){
    return !(x % y) ? y : gcd(y, x % y);
}
signed main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    f[1][1] = a[1];
    for(int i = 1; i <= n; i++){
        f[i][i] = a[i];
    }  
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            f[i][j] = gcd(a[j], f[i][j - 1]); 
        }
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        cout << f[x][y] << '\n';
    }
    system("pause");
    return 0;
}