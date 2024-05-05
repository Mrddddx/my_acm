#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[100];
int p[100];

void solve(){
    string s;
    int cost = 0;
    int add = 0;
    cin >> s;
    int len = 0;
    int n = s.size();
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') {
            len++;
        }
        if(s[i] == '0' && len != 0){
            cost += len + 1;
        }
    }
    cout << cost << '\n';
}
const int N = 1e5 + 5;
signed main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    system("pause");
    return 0;
}