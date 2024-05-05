#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
char str[N], pattern[N];
int nxt[N];
int cnt;
int len;
void getNext(char *p, int plen){
    nxt[0] = nxt[1] = 0;
    for(int i = 1; i < plen; i++){
        int j = nxt[i];
        while(j && p[i] != p[j])
            j = nxt[j];
        if(p[i] == p[j]) nxt[i + 1] = j + 1;
        else nxt[i + 1] = 0;
        //cout << p[i] << nxt[i + 1] << ' ';
    }
    len = plen;
    
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
        if(j == plen){
            cout << i + 2 - plen<< '\n';
        }
    }
}
int main(){
    scanf("%s", str);
    scanf("%s",pattern);
    cnt = 0;
    KMP(str, pattern);
    for(int i = 1; i <= len; i++){
        cout << nxt[i] << ' ';
    }
    system("pause");
    return 0;
}