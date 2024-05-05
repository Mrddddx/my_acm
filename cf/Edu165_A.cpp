#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[100];
int p[100];
void solve(){
    int n;
    cin >> n;
    int b = 0;
    
    for(int i = 1; i <= n ;i++){
        int x;
        cin >> x;
        f[x] = i;
        //cout << f[i]  << ' ' << x << '\n';
        if(f[i] == x) b = 1;
    }
    for(int i = 1; i <= n ;i++)
        f[i] = 0;
    if(b == 1) cout << 2 << '\n';
    else cout << 3 << '\n';
}
const int N = 1e5 + 5;
signed main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}