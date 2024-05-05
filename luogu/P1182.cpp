#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N];
int L, n, m;
int ans;
bool check(int d){
    ans = 1;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(sum + a[i] > d) ans++, sum = a[i];
        else sum += a[i];
        //cout << sum << ' ';
    }
    //cout << d << ' ' << ans << '\n';
    return ans <= m;
}

signed main(){
    cin >> n >> m;
    int l  = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        l = max(l, a[i]);
    }
    int r = 1e9, mid;
    while(l < r){
        mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    system("pause");
    return 0;
}