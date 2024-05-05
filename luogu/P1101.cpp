#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int b[110][110];
char ch[110][110];
int mx[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int my[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int n;
bool dfs(int x, int y, int cnt, int k){
    if(cnt == 7) return 1;
    if(a[x][y] == cnt + 1) if(dfs(x + mx[k], y + my[k], cnt + 1, k)) {b[x][y] = 1;return 1;}
    //cout << cnt << '\n';
    return 0;
    
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
    {
        cin >> ch[i][j];
        if(ch[i][j] == 'y') a[i][j] = 1;
        else if(ch[i][j] == 'i') a[i][j] = 2;
        else if(ch[i][j] == 'z') a[i][j] = 3;
        else if(ch[i][j] == 'h') a[i][j] = 4;
        else if(ch[i][j] == 'o') a[i][j] = 5;
        else if(ch[i][j] == 'n') a[i][j] = 6;
        else if(ch[i][j] == 'g') a[i][j] = 7;
        else a[i][j] = -1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(ch[i][j] == 'y'){
                for(int k = 1; k <= 8; k++)
                    if(dfs(i + mx[k], j + my[k], 1, k))
                    b[i][j] = 1;
            }
        }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            if(b[i][j]) cout << ch[i][j];
            else cout << '*';
        cout << endl;
    }
    system("pause");
    return 0;
}