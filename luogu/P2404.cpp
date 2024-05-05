#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10];
int n;

void dfs(int R, int num, int j){
    if(R == 0){
        if(num == 1) return;
        for(int i = 1; i < num;i++)
            cout << a[i] << '+';
        cout << a[num] << '\n';
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
    system("pause");
    return 0;
}