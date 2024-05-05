#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
const int M = 998244353;
int n, k;
int a[N];
inline int lowbit(int x) {return x & (-x);}
inline void update(int x, int k){
    for(int i = x + lowbit(x); i <= n; i += lowbit(i)){
        a[i] = ( k * M + a[i]  + k * a[x]) % M;
       
    }
}
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while(k --)
    for(int i = 1; i <= n; i++){
        update(i, 1);
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
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