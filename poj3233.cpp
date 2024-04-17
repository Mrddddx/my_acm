#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#define ll long long
struct matrix{
    ll m[101][101];
};
matrix A;
ll n, m, k;
ll N;
matrix operator* (const matrix &a, const matrix &b)
{
    matrix c;
    memset (c.m, 0, sizeof(c.m));
    for (int i = 1; i<= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % m;
    return c;
}

matrix pow_matrix()
{
    matrix ans;
    memset(ans.m, 0, sizeof(ans.m));
    for(int i = 1; i <= N; i++) ans.m[i][i] = 1;
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
    cin >> n >> k >> m;
    N = n * 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        { 
            cin >> A.m[i][j];
            A.m[i + n][j] = A.m[i][j];
        }
        A.m[i + n][i + n] = 1;
    }
    matrix ans = pow_matrix();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ans.m[i+n][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}