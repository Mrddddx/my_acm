#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        int t = (n - 1) >> 1;
        for (int i = t; i > 0; i--)
            cout << -1*i << ' ';
        cout << 0 << ' ';
        for (int i = 1; i <= n - t - 1; i++)
            cout << i << ' ';
        cout << endl;
    }
    system("pause");
    return 0;
}