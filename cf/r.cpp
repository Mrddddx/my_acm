#include<bits/stdc++.h>
using namespace std;
int n;
int a[110];
void solve()
{
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] ++; 
    }
    for(int i = 1; i <= 100; i++)
    {
        ans += a[i] / 3;
        a[i] = 0;
    }
    cout << ans << endl;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    system("pause");
}