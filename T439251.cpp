#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long  n, ans;
int main() 
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        ans = ((n % MOD) * (((n+1) % MOD) * ((2 *n+1) % MOD)% MOD )) % MOD / 6 ;
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
