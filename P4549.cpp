#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
int ans, n;
int gcd(int y, int x)
{
    return x ? gcd(x, y % x) : y;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ans = a[1];
    for (int i = 2; i <= n; i++)
        ans = gcd(ans, a[i]);
    cout << abs(ans);
    system("pause");
    return 0;
}
