#include <bits/stdc++.h>
using namespace std;
long long  n, k, m;
long long a[300300];
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
    long long ans = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int t = 1;
    while(k > 0)
    {
       
        if(k >= m)
             ans += a[t] * m,ans += m * (k - m);
        else ans += a[t] * k;
        k -= m;
        t ++;
    }
    cout << ans << endl;
 
    }
    system("pause");
    return 0;
}