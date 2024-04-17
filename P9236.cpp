#include <bits/stdc++.h> 
using namespace std;
long long  a[100200];
long long  w[200][2];
int n;
long long ans;
long long Xor[100100]; //前i个数的异或
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        Xor[i] = Xor[i - 1] ^ a[i];
    }
    for (int i = 0; i <= n; i++)
    for (int j = 20; j >=0 ;j--)
        w[j][(Xor[i] >> j) & 1] ++;
    for (int i = 0; i <= 20; i++)
        ans += w[i][0] * w[i][1] * (1 << i);
    cout << ans;
    system("pause");
    return 0;
}