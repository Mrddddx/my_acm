#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m;
int a[N];
int ans;
void Find(int x){
    int L = 1, R = n;
    if(x < a[1]) {ans += a[1] - x;return;}
    if(x > a[n]) {ans += x - a[n]; return;}
    while(L < R){
        int mid = L + R >> 1;
        if(a[mid] >= x) R = mid;
        else L = mid + 1;
    }
    ans += min(abs(a[L] - x), abs(x - a[L - 1]));
}
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        Find(x);
    }
    cout << ans;
    system("pause");
    return 0;
}