#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N];
int pre[N];
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int now = 0;
    sort(a + 1, a + 1 + n);
    int i;
    for(i = 2; i <= n; i++){
        now = (a[i] - a[i - 1]) * (i - 1);
        if(now > k) break;
        k -= now;
    }
    i --; //最小的是a[i]
    int hav = a[i]; //有hav 组完整的
    hav += k / i;
    k -= k / i * i;
    int ans = hav * n - (n - 1) + k + (n - i);
    cout << ans << '\n';

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