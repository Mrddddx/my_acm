#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int lowbit(int x)
{
    return x & (-x);
}
const int N = 2e5 + 5;
int n;
ll tree[N];
ll a[N], lager[N], lower[N];
void add(int x, int d)
{
    for(int i = x; i<= n; i += lowbit(i))
        tree[i] += d;
}
int sum(int x)
{
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += tree[i];
    return ans;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        int x = a[i];
        lager[i] = sum(n) - sum(x);
        lower[i] = sum(x - 1);
    }
    memset(tr)
}