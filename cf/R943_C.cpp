#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 10;
int a[N], x[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> x[i];
    }
    a[1] = x[1] + 1;
    for(int i = 2; i <= n; i++){
        a[i] = a[i - 1] + x[i - 1];
        while(a[i] <= x[i])  a[i] += a[i - 1];
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << ' ';
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