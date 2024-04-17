#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a, b, m;
ll fastPow(ll a, ll b, ll m)
{
    ll ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
int main()
{
    
    cin >> a >> b >> m;
    ll ans = fastPow(a, b, m);
    printf("%lld^%lld mod %lld=%lld",a,b,m,ans);
    
    system("pause");
    return 0;
}