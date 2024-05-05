#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100];
int n;
int ans;
void dfs(int R, int num, int j){
    if(R == 0){
        ans ++;
        return ;
    }
    for(int i = j; i <= R; i++){
        a[num + 1] = i;
        dfs(R - i, num + 1, i);
    }
    
}
signed main(){
    cin >> n;
    dfs(n, 0, 1);
    cout << ans;
    system("pause");
    return 0;
}