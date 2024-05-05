#include<bits/stdc++.h>
using namespace std;
char ch[10][1010];
int one, two;
int main(){
    int n, h;
    cin >> n >> h;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= n; j++){
            cin >> ch[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(ch[2][i] == '*') one++;
        if(ch[4][i] == '*') one++;
        if(ch[1][i] == '*')
            if(ch[2][i] == '*') one++;
            else two++;
        if(ch[5][i] == '*'){
            if(ch[4][i] == '*') one++;
            else two++;
        }
    }
    int ans = 0;
    //cout << one << ' ' << two;
    if(h <= one) ans = h;
    else
        {
            ans += one;
            int rh = h - one;
            if(rh >= two * 2) ans += two;
            else ans += (rh >> 1);
        }
    cout << ans;
    system("pause");
    return 0;
}