#include <bits/stdc++.h> 
using namespace std;
int a[200200];
int n;
int maxn = -1 * 0xfffffff;
int dp[200200];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = max(dp[i - 1] + a[i] , a[i]);
    }
    for (int i = 1; i <= n; i++)
        maxn = max(dp[i] , maxn);
    cout << maxn;
    system("pause");
    return 0;
}