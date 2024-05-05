#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
//结构体
struct node{
    int son[26];
    int end;
    int fail;
} t[N];

int cnt;
void Insert(char *s){
    int now = 0;
    for(int i =0; s[i]; i++){
        int ch = s[i] - 'a';
        if(t[now].son[ch] == 0)
            t[now].son[ch] = cnt++; 
        now = t[now].son[ch];
    }
    t[now].end++;
}
void getFail(){
    queue<int> q;
    for(int i = 0; i < 26; i++)
        if(t[0].son[i])
            q.push(t[0].son[i]);
    while(!q.empty()){
        int now = q.front();    q.pop();
        for(int i = 0; i < 26; i++){
            if(t[now].son[i]) {
               t[t[now].son[i]].fail = t[t[now].fail].son[i];
               q.push(t[now].son[i]);
        }
        else
            t[now].son[i] = t[t[now].fail].son[i];
        }
    }
}
int query(char *s){
    int ans =0,  now = 0;
    int l = strlen(s);
    for(int i = 0; i < l; i++){
        int ch = s[i] - 'a';
        now = t[now].son[ch];
        for(int tmp = now; tmp && t[tmp].end != -1; tmp = t[tmp].fail)
        {
            ans += t[tmp].end;
            t[tmp].end = -1;
        }
    }
    return ans;                     
}
char str[N];
int main(){
    cnt = 1;
    int n;   cin >> n;
    while(n--){
        scanf("%s", str);
        Insert(str);
    }
    getFail();
    
    scanf("%s",str);
    cout << query(str);
    system("pause");
    return 0;
}