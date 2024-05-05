#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 5;
int a[N];
int L, n, m;
int ans;
bool check(int d){
    ans = 0; int last = 0;
    for(int i = 1; i <= n + 1; i++){
        if(a[i] - last < d) ans++;
        else last = a[i];
    }
    //cout << ans << '\n';
    return ans <= m;
}

signed main(){
    cin >> L >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[n + 1] = L;
    sort(a + 1, a + 1 + n);
    int l = 1, r = L + 1, mid;
    while(l + 1 < r){
        mid = l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    system("pause");
    return 0;
}