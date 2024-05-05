#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    cout << "1 1\n" << n << ' ' <<n <<'\n';
    int d = 0, t = 0;;
    int len = n * 2 - 1;
    for(int i = 1; i <= n - 2; i++){
        d ++;
        if((d + 1) % 2 == 0 && d != 1) t++;
        int x, y;
        if(i & 1) x = t + 1, y = 1 + d;
        else x = n - t, y = n - d;
        cout << x << ' ' << y << '\n';
    }
}
signed main(){
    int T;
    cin >> T;
    while(T--){
        solve();
        if(T) cout << '\n';
    }
    system("pause");
    return 0;
}