#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int a[100];
int b[100];
int n;
int ans;
void dfs(int s, int k, int x, int f)
{
    if(f) ans = min(ans, abs(s - k));
    if(!x) return;
    dfs(s * a[x], k + b[x], x - 1, 1);
    dfs(s, k, x - 1, f);
}
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    ans = abs(a[1] - b[1]);
    dfs(1, 0, n, 0);
    cout << ans;
    system("pause");
    return 0;
}