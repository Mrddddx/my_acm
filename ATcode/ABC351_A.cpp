#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 0, b = 0;
    for(int i = 1; i <= 9; i++){
        int x;
        cin >> x;
        a += x;
    }
    for(int i = 1; i <= 8; i++){
        int x;
        cin >> x;
        b += x; 
    }
    int ans = a - b + 1;
    cout << ans; 
    system("pause");
    return 0;
}