#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int p;
int n;
struct matrix{long long m[110][110];} A;
matrix operator* (const matrix& a, const matrix& b)
{
    matrix c;
    memset(c.m, 0, sizeof(c.m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
            c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
    return c;
}
matrix pow_matrix(long long k)
{
    matrix ans;
    memset(ans.m, 0, sizeof(ans.m));
    for (int i = 0; i < n; i++) ans.m[i][i] = 1;
    while(k)
    {
        if(k & 1) ans = ans * A;
        A = A * A;
        k >>= 1;
    }
    return ans;
}
int main()
{
    long long k;
    n = 2;
    A.m[0][0] = 1, A.m[0][1] = 1, A.m[1][0] = 1, A.m[1][1] = 0,
    cin >> k ;
    matrix ans = pow_matrix(k);
    cout << ans.m[0][1];
    system("pause");
    return 0;
}