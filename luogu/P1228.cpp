#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n;
int tx, ty; //target
struct st{
    int x, y, num;
} ans[N];
int cnt;
int place(int x, int y, int tx, int ty){
    if(tx <= x && ty <= y) {ans[++cnt].num = 1; ans[cnt].x = x + 1; ans[cnt].y = y + 1; return 1;}
    if(tx <= x && ty > y) {ans[++cnt].num = 2; ans[cnt].x = x + 1; ans[cnt].y = y; return 3;}
    if(tx > x && ty <= y) {ans[++cnt].num = 3; ans[cnt].x = x; ans[cnt].y = y + 1; return 2;}
    if(tx > x && ty > y) {ans[++cnt].num = 4; ans[cnt].x = x; ans[cnt].y = y; return 4;}
    return 0;
}
void dfs(int x1, int y1, int x2, int y2, int tx, int ty, int n){
    int midx = x1 + x2 >> 1;
    int midy = y1 + y2 >> 1;
    int nxt = place(midx, midy, tx, ty);
    if(n == 1) return; 
    if(nxt == 1){
        dfs(x1, y1, midx, midy, tx, ty, n - 1);
        dfs(x1, midy, midx, y2, midx, midy + 1, n - 1);
        dfs(midx, y1, x2, midy, midx + 1, midy, n - 1);
        dfs(midx, midy, x2, y2, midx + 1, midy + 1, n - 1);
    }
    else if(nxt == 2){
        dfs(x1, y1, midx, midy, midx, midy, n - 1);
        dfs(x1, midy, midx, y2, midx, midy + 1, n - 1);
        dfs(midx, y1, x2, midy, tx, ty, n - 1);
        dfs(midx, midy, x2, y2, midx + 1, midy + 1, n - 1);
    }
    else if(nxt == 3){
        dfs(x1, y1, midx, midy, midx, midy, n - 1);
        dfs(x1, midy, midx, y2, tx, ty, n - 1);
        dfs(midx, y1, x2, midy, midx + 1, midy, n - 1);
        dfs(midx, midy, x2, y2, midx + 1, midy + 1, n - 1);
    }
    else if(nxt == 4){
        dfs(x1, y1, midx, midy, midx, midy, n - 1);
        dfs(x1, midy, midx, y2, midx, midy + 1, n - 1);
        dfs(midx, y1, x2, midy, midx + 1, midy, n - 1);
        dfs(midx, midy, x2, y2, tx, ty, n - 1);
    }
}
int main()
{
    cin >> n ;
    cin >> tx >> ty;
    int L = 1, R = 1 << n;
    dfs(L , L, R, R, tx, ty, n);
    for(int i = 1; i <= cnt; i++){
        cout << ans[i].x << ' ' << ans[i].y << ' ' << ans[i].num << '\n';
    }
    system("pause");
    return 0;
}