#include<bits/stdc++.h>
using namespace std;
void change(int n, int r){
    if(n == 0) return;
    int m = n % r;
    if(m < 0) m -= r, n += r;
    if(m >= 10) m = 'A' + m - 10;
    else m += '0';
    change(n / r, r);
    cout << (char) m;
    return;
}
int main() {
    int n , r;
    cin >> n >> r;
    cout << n << '=';
    change(n, r);
    cout << "(base" << r << ')';
    system("pause");
    return 0;
}