#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 30;
char ch[N][N << 1];
void init(int x, int y){
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
            ch[i][j] = ' ';
}
void dfs(int L, int R,int top, int y, int n)
{
    if(n == 1){
        ch[y][L] = '/';
        ch[y][R] = '\\';
        ch[y - 1][L + 1] = '/';
        ch[y - 1][R - 1] = '\\';
        ch[y][L + 1] = ch[y][R - 1] = '_';
        return;
    }
    int mid = L + R >> 1;
    int midl = (L + mid >> 1) + 1;
    int midr = R + mid >> 1;
    dfs(L, mid, top + y >> 1, y, n - 1);
    dfs(mid + 1, R, top + y >> 1, y, n - 1);
    dfs(midl, midr, top, top + y >> 1, n - 1);
}
int main()
{
    int n;
    cin >> n;
    int L = 1, R = 1 << n + 1;
    int y = 1 << n;
    init(y, R);

    dfs(L , R, 1, y, n);
    for(int i = 1; i <= y; i++){
        for(int j = 1; j <= R; j++)
            cout << ch[i][j];
            cout << endl;
    }  
    system("pause");
    return 0;
}