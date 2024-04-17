#include <bits/stdc++.h>
using namespace std;
double x, n;
double ans;
int ansWer;
int main()
{
    cin >> x >> n;
    if(x == 2 && n > 2) {cout << "inf"; return 0;}
    if(x == 2 && n == 1) {cout << 0; return 0;}
    if(x == 2 && n == 2) {cout << 1; return 0;}
    n -= 2 ;

    ans = n / (log2(x) - 1);
    
    ansWer =ceil(log2(ans));
    cout << ansWer;
    system("pause");
    return 0;
}