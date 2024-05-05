#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[31];
int n;
int edge[31][31];
int b[31];
int maxn = 0;
void dfs(int p, int len){
    maxn = max(maxn, len);
    for(int i = 1; i <= n; i++){
        if(edge[p][i] && b[i] < 2){
            b[i]++;
            dfs(i, len + s[i].size() - edge[p][i]);
            b[i]--;
        } 
    }
}
signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
       cin >> s[i]; 
    }
    char ch;
    cin >> ch;
    for(int i = 1; i <= n; i++){
        if(s[i][0] == ch) edge[0][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int f = 0;
            for(int k = 1; k < s[i].size(); k++){
                if(s[i][k] != s[j][0]) continue;
                int x = 1;
                while(x + k < s[i].size() && k < s[i].size() && s[i][k + x] == s[j][x]) x++;
                if(x + k == s[i].size() && x < s[j].size()){
                    f = x;
                }
            }
            edge[i][j] = f;
        }
    }
    //for(int i = 0; i <= n; i++)
      //  for(int j = 1; j <= n; j++)//
        //    cout << s[i] << ' ' << s[j] << ' ' << edge[i][j] << '\n';
    for(int i = 1; i <= n; i++){
        if(edge[0][i]) b[i]++, dfs(i, s[i].size()), b[i]--;
    }
    cout << maxn;
    system("pause");
    return 0;
}