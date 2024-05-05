#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int ans, lenb;
char a[N], b[N];
int nxt[N];
void exkmp1(){
    int p = 0, k = 1, l;
    nxt[0] = lenb;
    while(p + 1 < lenb && b[p] == b[p + 1]) p++;
    nxt[1] = p;
    for(int i = 2; i < lenb; i++){
        p = nxt[k] + k - 1;
        l = nxt[i - k];
        if(i + l <= p) nxt[i] = l;
        else {
            int j = max(0, p - i + 1);
            
        }
    }
}
int exkmp(string s){

}

int main(){
    scanf("%s", b);
    scanf("%s", a);
    lenb = strlen(b);
    exkmp1();
    system("pause");
    return 0;
}