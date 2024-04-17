#include <bits/stdc++.h>
using namespace std;

long long  sum;
int a[202020];

long long ans;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 1; i < n; i++)
    {
        ans +=(sum - a[i]) * a[i];
        sum -= a[i];
    }
    cout << ans;
    system("pause");
    return 0;
}

