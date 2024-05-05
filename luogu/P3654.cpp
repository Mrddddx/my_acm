#include<bits/stdc++.h>
using namespace std;
int ans;
int n, m, k;
int a[110][110];
char ch[110][110];

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> ch[i][j];
            if(ch[i][j] == '#') a[i][j] = 0;
            else a[i][j] = 1;
        }
    for(int i = 1; i <= n; i++){
        int now = 0;
        for(int j = 1; j <= m + 1; j++)
        {
            if(a[i][j] == 0) ans += max(0, now - k + 1),now = 0;
            now +=a[i][j];
        }
    }
    
    for(int i = 1; i <= m; i++){
        int now = 0;
        for(int j = 1; j <= n + 1; j++)
        {
            if(a[j][i] == 0) ans += max(0, now - k + 1),now = 0;
            now +=a[j][i];
        }
    }
    if(k == 1) ans >>= 1;
    cout << ans;
    system("pause");
    return 0;

}