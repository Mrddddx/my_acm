#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int a[N], b[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    int Ins = 0;
    for(int i = 1; i <= n ;i++){
        if(b[i] < a[i - Ins] ) Ins++;
    }
    cout << Ins << '\n';
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