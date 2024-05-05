#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
void solve(){
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> id;
    id[0].push_back(0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ^= a[i - 1];
        id[a[i]].push_back(i);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        if(a[r] == a[l - 1]){
            cout << "YES\n";
            continue;
        }
        int s = *--lower_bound(id[a[l - 1]].begin(), id[a[l - 1]].end(), r);
        int t = *lower_bound(id[a[r]].begin(), id[a[r]].end(), l);
        if(s > t) cout << "YES\n";
        else cout << "NO\n";
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