#include<bits/stdc++.h>
using namespace std;
struct Node{
    int son[26];
    int end;
    int isend;
} f[2010];
int cnt;
int maxn;
void Insert(char *s){
    int now = 0;
    for(int i = 0; s[i]; i++){
        char ch = s[i] - 'a';
        if(!f[now].son[ch]){
            f[now].son[ch] = ++ cnt;
        }
        now = f[now].son[ch];
        if(f[now].isend) f[now].isend = 0; 
    }
    f[now].end ++;
    f[now].isend = 1;
}
void dfs(int now, int ans){
    if(f[now].isend) {maxn = max(ans, maxn); return;}
    for(int i = 0; i < 26; i++){
        if(!f[now].son[i]) continue;
        //cout << char(i + 'a') << ' ';
        ans += f[f[now].son[i]].end;
        //if(f[now].end)
        dfs(f[now].son[i], ans);
        ans -= f[f[now].son[i]].end;
    }
}
char str[100];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        scanf("%s", str);
        Insert(str);   
    }
    dfs(0, 0);
    cout << maxn;
    system("pause");
    return 0;
}