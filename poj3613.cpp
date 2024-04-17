#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#define ll int 
const int Inf = 0x3f;

struct matrix{
    ll m[121][121];
};
int Hash[1005] , cnt;
matrix A;
ll n, m;
ll N;
int t, s, e;
matrix operator * (const matrix &a, const matrix &b)
{
    matrix c;
    memset (c.m, 0x3f, sizeof(c.m));
    for (int i = 1; i<= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {   
            for (int k = 1; k <= N; k++)
                c.m[i][j] =min(c.m[i][j] , a.m[i][k] + b.m[k][j]);
        }
    }
    return c;
}

matrix pow_matrix(int k)
{
    matrix ans = A;
    k --;
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
    cin >> n >> t >> s >> e;
    memset (A.m, 0x3f, sizeof(A.m));
    while(t --)
    {
        int u, v, w;
        cin >> w >> u >> v;
        if(!Hash[u]) Hash[u] = ++cnt;
        if(!Hash[v]) Hash[v] = ++cnt;
        A.m[Hash[u]][Hash[v]] = A.m[Hash[v]][Hash[u]] = w;
    }
    N = cnt;
    matrix ans = pow_matrix(n);
    cout << ans.m[Hash[s]][Hash[e]];
    system("pause");
    return 0;
}