#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5 + 10;
const ll M = 1e9 + 7;
int n, k;
ll a[N];
void pre()
{
    a[0] = 1;
    a[1] = 1;
    a[2] = 3;
    for(int i = 3; i <= N; i++)
        a[i] = (a[i - 1] + a[i - 2] * (i - 1) * 2) % M;
}
void solve()
{
    cin >> n >> k;
    while(k --)
    {
        int x, y;
        cin >> x >> y;
        if(x == y) n--;
        else n -= 2;
    }
    cout << a[n] << endl;
}
int main()
{
    int T;
    cin >> T;
    pre();
    while(T--)
    {
        solve();
    }
    
    system("pause");
}