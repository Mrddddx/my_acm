#include<bits/stdc++.h>
using namespace std;
#define ll long long
int lr[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int ud[9] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
int a[100][100];
ll ans[100][100];
int main()
{
    int n, m, tx, ty;
    cin >> n >> m;
    cin >> tx >> ty;
    a[tx][ty] = 1;
    for(int i = 1; i <= 8; i++){
        int u = tx + ud[i];
        int l = ty + lr[i];
        if(u >= 0 && l >= 0 && u <= n && l <= m) {
            a[u][l] = 1;
            //cout << u << ' ' << l << '\n';
        }
    }
    ans[0][0] = 1; 
    for(int i = 1; i <= n; i++)
        if(!a[i][0]) ans[i][0] = ans[i - 1][0];
    for(int i = 1; i <= m; i++)
        if(!a[0][i]) ans[0][i] = ans[0][i - 1];
         
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(!a[i][j])
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1];

    cout << ans[n][m];
    system("pause");
    return 0;
}