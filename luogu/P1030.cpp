#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(string x, string y){
    if(x.size()){
        char ch = y[y.size() - 1];
        cout << ch;
        int k = x.find(ch);
        dfs(x.substr(0, k), y.substr(0, k));
        dfs(x.substr(k + 1), y.substr(k, y.size() - k - 1));
    }
}
signed main(){
    string s1, s2;
    cin >> s1 >> s2;
    dfs(s1, s2);
    system("pause");
    return 0;
}