#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 5e5 + 5;
int n;
ll a[N], b[N];
int ans;
ll sum, now;
int main()
{   
    int T;
    cin >> T;
    while (T--)
    {  
    now = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {   cin >> a[i];    sum += a[i];}
    sort(a + 1, a + n + 1);

    if (a[n] > (sum >> 1)) //直接拿最大的然后大于剩余
    {
        cout <<"YES\n";
        continue;
    }
    int i = 1, j = 1, k = 0;
    int t = 0; // 数组b的个数，
    while (k < n - 1)
    {
        int w, m;
        if (a[i] > b[j] && j <= t  || i > n)
        {
            w = b[j];
            j++;
        }
        else 
        {
            w = a[i];
            i++;
        }

        if (a[i] > b[j] && j <= t  || i > n)
        {
            m = b[j];
            j++;
        }
        else 
        {
            m = a[i];
            i++;
        }
        now = m + w;
        //cout << now <<'A';
        if (now > a[n])  swap(now, a[n]); 
        b[++t] = now; 
        k++; 
        if(a[n] > (sum >> 1)) 
        {
            ans = k;
            break;
        }
    }
    if(ans % 2 == 1) cout <<"NO\n";
    else cout << "YES\n";

    
    }
    system("pause");
    return 0;
}