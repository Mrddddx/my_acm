#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[101];
int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
        {
            int x = 0;
            for (int k = i; k <=j; k++)
            x ^= a[k];
            ans += x;
        }
    cout << ans;
    system("pause");
    return 0;
}