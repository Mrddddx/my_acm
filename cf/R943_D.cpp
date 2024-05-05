#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int p[N], a[N];
int n, k, B, S;
int score(int s, int K){
    int mx = 0, cur = 0;
    vector<bool> vis(n + 1);
    while(!vis[s] && K > 0){
        vis[s] = 1;
        mx = max(mx, cur + 1ll * K * a[s]);
        cur += a[s];   
        K --;
        s = p[s];
    }
    return mx;
}
void solve(){
    cin >> n >> k >> B >> S;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int A = score(B, k);
    int B = score(S, k);
    //cout << A << ' ' << B << '\n';
    if(A > B) cout << "Bodya\n";
    if(A < B) cout << "Sasha\n";
    if(A == B) cout << "Draw\n";
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