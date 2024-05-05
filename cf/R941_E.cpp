#include<bits/stdc++.h>
using namespace std;

void solve(){
    int mx = 0, mn = 0;
    int n ;
    cin >> n;
    char ch;
    int x = 0;
    for(int i = 1; i <= n; i++){
        cin >> ch;
        if( (ch == '1') ^ (i & 1)) x++;
        else x--;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    cout << mx - mn << '\n';
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