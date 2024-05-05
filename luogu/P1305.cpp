#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct Node{
    int l, r;
} tree[30];
void dfs(int x){
    cout << (char)(x + 'a');
    if(~tree[x].l) dfs(tree[x].l);
    if(~tree[x].r) dfs(tree[x].r);
}
signed main(){
    cin >> n;
    string s;
    int root;
    for(int i = 1; i <= n ;i++){
        cin >> s;
        
        int fa = s[0] - 'a';
        if(i == 1) root = fa;
        if(s[1] == '*') tree[fa].l = -1;
        else tree[fa].l = s[1] - 'a';
        if(s[2] == '*') tree[fa].r = -1;
        else tree[fa].r = s[2] - 'a';
    }
    dfs(root);
    system("pause");
    return 0;
}