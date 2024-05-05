#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
int a[110];
int b[110];
void solve(){
    int n, k;
    memset(b, 0, sizeof b);
    cin >> n >> k;
    int f = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]]++;
        if(b[a[i]] == k) f = 1;
    }
    if(f == 1){
        cout << k - 1 << '\n';
    }
    else cout << n << '\n';
}
int main()
{
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}