#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char str[N], pattern[N];
int nxt[N];
int cnt;
void getNext(char *p, int plen){
    nxt[0] = nxt[1] = 0;
    for(int i = 1; i < plen; i++){
        int j = nxt[i];
        while(j && p[i] != p[j])
            j = nxt[j];
        if(p[i] == p[j]) nxt[i + 1] = j + 1;
        else nxt[i + 1] = 0;
    }
    for(int i = 0; i <= plen; i++)
        cout << nxt[i] << ' ';
    cout << '\n';
    return ;
}

void KMP(char *s, char *p){
    int last = -1;
    int slen = strlen(s), plen = strlen(p);
    getNext(p, plen);
    int j = 0;
    for(int i = 0; i < slen; i++){
        while(j && s[i] != p[j])
            j = nxt[j];
        if(s[i] == p[j]) j++;
        if(j == plen && i - last >= plen){
            cnt ++;
            last = i;
        }
    }
}
int main(){
    while(~scanf("%s", str)){
        if(str[0] == '#') break;
        scanf("%s",pattern);
        cnt = 0;
        KMP(str, pattern);
        cout << cnt << '\n';
    }
}