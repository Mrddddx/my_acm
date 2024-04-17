#include<bits/stdc++.h>
using namespace std;  
const int N = 1e3 + 3;
int a[N][N];
int line[10], row[10], xxx[2];
long long ans;
int blk, wht; 
void show()
{
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++)
            cout << a[i][j];
        cout << endl;
    }
    system("pause");
    return;
}
void dfs(int x, int y)
{
    if(blk == 13 && wht == 12)
    {
        show();
        ans ++;
        return;
    }
    if(y == 6) {dfs(x + 1, 1); return;}
    if(x == 6) return;
    
    if(line[x] + 1 < 5 && row[x] + 1 < 5)
        if((x != y || xxx[0] + 1 < 5) && (x + y != 6 || xxx[1] + 1 < 5))
    {
        a[x][y] = 1;
        blk ++, line[x] ++; row[y] ++;
        if(x == y) xxx[0] ++;
        if(x + y == 6) xxx[1] ++;
        dfs(x, y + 1);
        blk --, line[x] --; row[y] --;
        if(x == y) xxx[0] --;
        if(x + y == 6) xxx[1] --;
    }
    if(line[x] - 1 > -5 && row[x] - 1 > -5)
        if((x != y || xxx[0] -1 > -5) && (x + y != 6 || xxx[1] - 1 > -5))
    {
         a[x][y] = 0;
        wht ++, line[x] --; row[y] --;
        if(x == y) xxx[0] --;
        if(x + y == 6) xxx[1] --;
        dfs(x, y + 1);
        wht --, line[x] ++; row[y] ++;
        if(x == y) xxx[0] ++;
        if(x + y == 6) xxx[1] ++;
    }
}

int main()
{  
    dfs(1, 1);
    cout << ans << endl;
    system("pause");
} 

 