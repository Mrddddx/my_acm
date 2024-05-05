#include<bits/stdc++.h>
using namespace std;
const int N = 8e5 + 5;
struct Node{
    bool repeat; //前缀是否重复
    int son[26];
    int num;
    bool isend;
} t[N];
int cnt = 1;

void Insert(char *s){
    int now = 0;
    for(int i = 0; s[i]; i++){
        int ch = s[i] - 'a';
        if(t[now].son[ch] == 0)
            t[now].son[ch] = cnt ++;
        now = t[now].son[ch];
        t[now].num ++;
        if(i == strlen(s)- 1) t[now].isend = true;
    }
}
int Find(char *s){
    int now = 0;
    for(int i = 0; s[i]; i++){
        int ch = s[i] - 'a';
        if(t[now].son[ch] == 0) return 3;
        now = t[now].son[ch];
    }
    if(t[now].isend == false) return 3;
    if(t[now].num == 0) return 3;
    if(t[now].repeat == false){
        t[now].repeat = true;
        return 1;
    }  
    return 2;
}
int main(){
    char s[51];
    int n; cin >> n;
    while(n--){
        cin >> s;
        Insert(s);
    }
    int m; cin >> m;
    while(m--){
        cin >> s;
        int r = Find(s);
        if(r == 1) puts("OK");
        if(r == 2) puts("REPEAT");
        if(r == 3) puts("WRONG");
    }
    system("pause");
    return 0;
}