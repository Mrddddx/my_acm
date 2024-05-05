#include<bits/stdc++.h>
using namespace std;
const int  base = 1e9;
const int  N = 1e4 + 10;
struct Int{
    int len, n[N / 9 + 10];
    Int(){}
    Int(char *s){
        int x = strlen(s);
        len = x / 9 + (x % 9 ? 1 : 0);
        int p = x - 1;
        for(int i = 1; i <= len; i++){
            n[i] = 0;
            for(int j = min(p, 8); j >= 0; j--)
                n[i] = n[i] * 10 + (s[p - j] & 15);
            p -= 9;
        }
    }
}
int main(){

}