#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 5e5 + 5;
priority_queue<ll , vector<ll> , greater<ll> > q;
int n;
ll maxn; 

ll half, now;
int main()
{   
    int T;
    cin >> T;
    while (T--)
    {

    while(!q.empty()) q.pop();
    maxn = 0;
    half = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {   
        ll x;
        cin >> x;    
        half += x;     
        maxn = max(x, maxn);
        q.push(x);
    }
    
    half >>= 1;
    //cout << half;
    if (maxn > half) //直接拿最大的然后大于剩余
    {
        cout <<"YES\n";
        continue;
    }
    int k = 0;
    while(!q.empty())
    {
        k++;
        ll x, y, sum;
        x = q.top(), q.pop();
        y = q.top(), q.pop();
        //cout << x << y << 'A';
        sum = x + y;
        maxn =  maxn = max(sum, maxn);
        q.push(sum);
        if(maxn > half) 
            break;
    }
    if(k & 1) cout <<"NO\n";
    else cout <<"YES\n";

    }
    system("pause");
    return 0;
}