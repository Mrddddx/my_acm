#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char c[N][N];
int a[N][N];
inline bool check(int x, int y){
    if(c[x + 1][y] == '#' || c[x - 1][y] == '#' || c[x][y + 1] == '#' || c[x][y - 1] == '#')
        return true; 
    return false; 
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> c[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(c[i][j] == '#') a[i][j] = 2;
            else if(check(i, j)) a[i][j] = 1;  
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            
        }
    system("pause");
    return 0;
}