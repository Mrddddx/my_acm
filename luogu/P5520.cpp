#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int a[N];
int ans;
signed main(){
    int n, m , type, p;
    cin >> type >> n >> m >> p;
    int k = n - m;
    a[0] = 1;
    int f;
    if(m > (n >> 1) + !!(n & 1)) f = 0;
    for(int i = 1; i <= m; i++){
        a[i] = (a[i - 1] + a[i - 1] * k / i) % p;
        cout << a[i] << ' ';
    }
    ans = a[m];
    a[0] = 0;
    ans = (a[m] - a[m - 1]) % p;
    for(int i = 1; i <= m; i++)
    ans = (ans * i) % p;
    if(f) cout << ans;
    else cout << 0;
    system("pause");
    return 0;
}