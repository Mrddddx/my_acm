#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int f[N];
int v[N], w[N];
int n, W;
int main()
{
    cin >> n >> W;

    for (int i = 1; i <= n; i ++)
        cin >> w[i] >> v[i];
    for(int i = 1; i <= n; i++)
        for(int j = W; j >= w[i]; j--)
            f[j] = max (f[j], f[j - w[i]] + v[i]);
    int ans1 = f[W];
    memset(f, 128, sizeof f);
    f[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = W; j >= w[i]; j--)
            f[j] = max (f[j], f[j - w[i]] + v[i]);
    int ans2 = f[W];
    cout << ans1 << endl << max(0, ans2);
    system("pause");
    return 0;
}