#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
char ch[N][N];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ch[i][j];
        }
    }
    int top = 0, left = 0, right = 0, bottom = 0;
    for(int i = 1; i <= m; i++)
    {
        if(ch[1][i] == 'B') top ++;
        else top--;
        if(ch[n][i] == 'B') bottom++;
        else bottom--;
    }
    for(int i = 1; i <= n; i++)
    {
        if(ch[i][1] == 'B') left ++;
        else left--;
        if(ch[i][m] == 'B') right++;
        else right--;
    }
    //cout << left << right << top << bottom << '\n';
    if((left == -right && abs(left) == n) || (top == - bottom && abs(top) == m))
        cout << "NO\n";
    else cout << "YES\n";
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