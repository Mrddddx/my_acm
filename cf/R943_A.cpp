#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    return !(a % b) ? b : gcd(b, a % b);
}
void solve(){
    int n;
    int maxn = 0;
    cin >> n;
    int y = 1;
    for(int i = 1; i < n; i++){
        int u = (n, i) + i;
        if(u >= maxn) maxn = u, y = i;
        
    }
    cout << y << '\n';
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}