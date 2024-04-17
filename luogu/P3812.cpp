#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll p[101];
ll ans;
int M = 50;
void Insert(ll x)
{
    for(int i = M; i >=0; i--)
        if(x >> i == 1)
            if(!p[i]) p[i] = x;
            else x ^= p[i];
}
void Compute()
{
    for(int i = M; i >= 0; i --)
        ans = max(ans, ans ^ p[i]);
}
int main()
{
    int n;
    ll x;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        Insert(x);
    }
    Compute();
    cout << ans;
    system("pause");
    return 0; 
}