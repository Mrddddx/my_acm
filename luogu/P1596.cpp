#include<bits/stdc++.h>
using namespace std;
#define int long long
int ud[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int lr[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
char ch[110][110];
int b[110][110];
int n, m;
int ans;
void dfs(int x, int y){
    //cout << x << ' ' << y << '\n';
    for(int i = 1; i <= 8; i++){
        int u = x + ud[i], l = y + lr[i];
        if(u && l && u <= n && l <= m && !b[u][l]){
            b[u][l] = 1;
            dfs(u, l);
        }
    }
}
signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ch[i][j];
            if(ch[i][j] == '.') b[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(ch[i][j] == 'W' && !b[i][j])
                b[i][j] = 1,dfs(i, j), ans++;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}