#include<bits/stdc++.h>
using namespace std;
int a, b;
bool cheak1(int x){
    int xx = x;
    int y = 0;
    while(xx){
        y = y * 10 + xx % 10;
        xx /= 10;
    }
    if(x == y) return 1;
    else return 0;
}
bool cheak2(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}
int main(){

    cin >> a >> b;
    for(int i = a; i <= min(b, 9999999); i++){
        if(!cheak1(i)) continue;
        if(!cheak2(i)) continue;
        cout << i << '\n';
    }
    system("pause");
    return 0;
}