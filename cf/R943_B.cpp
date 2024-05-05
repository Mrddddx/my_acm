#include<bits/stdc++.h>
using namespace std;
void solve(){
    string a, b;
    int n, m;
    cin >> n >> m;
    cin >> a >> b;
    int j = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(j < m && a[i] != b[j]) j++;
        //cout << i << ' ' << j <<'\n';
        if(j == m) break;
        j++;
        ans++;
    }
    cout << ans << '\n';
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}