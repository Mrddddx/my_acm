#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n, k;
bool check(int x){
    if(x == 0) return 1;
    cout << x << ' ';
    int ans = 1;
    for(int i = x; i < n; i++){
        if(s[0] == s[i]){
            int j = 0;
            while(j < x && j + i < n && s[j] == s[x + j]) j++;
                if(j == x) ans++;
            i += j - 1;
        }
        cout << i << ' ';
    }
    cout << "\n ans = " << ans << '\n';
    return ans >= k;
}
void solve(){
    cin >> n >> k >> k;
    cin >> s;
    if(k == 1) {cout << n; return;}
    int L = 1, R = n / k + 1;
    while(L < R){
        int mid = L + R >> 1;
        if(check(mid)) L = mid + 1;
        else R = mid;
    }
    if(check(R)) cout << R;
    else cout << R - 1;
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