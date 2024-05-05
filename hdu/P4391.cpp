#include<bits/stdc++.h>
using namespace std;
char A[1008611], B[1008611];
int n;
int nxt[1008611];
int ori[1008611];
stack<char> ch;
stack<int> c;
char ans[1008611];
int cnt; 
void getNext(string s, int len){
    nxt[1] = nxt[0] = 0;
    ori[0] = 0;
    for(int i = 1; i < len; i++){
        int j = nxt[i];
        while(j && s[j] != s[i])
            j = nxt[j];
        if(s[j] == s[i]) nxt[i + 1] = j + 1;
        else nxt[i + 1] = 0;
    }
    
    /*for(int i = 0; i < len; i++)
        cout << s[i] << ' ';
    cout << '\n';
    for(int i = 0; i < len; i++)
        cout << nxt[i] << ' ';*/
}
int sz;
void KMP(){
    int j = 0;
    for(int i = 0 ; i < n; i++){
        ch.push(A[i]);
        c.push(i);
        while(j && A[i] != B[j]) 
            j = nxt[j];
        if(A[i] == B[j]) j++;
        ori[i] = j;
        if(j == sz){
            for(int k = 1; k <= sz; k++) 
            {    ch.pop();c.pop();}
            //cout << ch.size();
            if(c.size())j  = ori[c.top()] ;
            else j = 0;
        }
    }
}
int main(){
    scanf("%s", A);
    scanf("%s", B);
    n = strlen(A);
    sz = strlen(B);
    getNext(B, sz);
    KMP();
    while(ch.size()){
        //cout << cnt;
        ans[++cnt] = ch.top();
        ch.pop();
    }
    for(int i = cnt; i >= 1; i--)  
        cout << ans[i];
    system("pause");
    return 0;
}