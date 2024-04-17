#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;
ll ten[N], dp[N];
ll cnta[N], cntb[N]; // cnt 统计
int num[N];
void init(){
    ten[0] = 1; // ten[i]:10的i次方
    for(int i = 1; i <= N; i++){  
        dp[i] = i * ten[i - 1]; 
        ten[i] = 10 * ten[i - 1];
    }
}

void solve(ll x, ll *cnt)
{
    int len = 0;
    while(x)
    {
        num[++len] = x % 10; //统计位数
        x = x / 10;
    }
    for(int i = len; i >= 1; i--)
    {
        for(int j = 0; j <= 9; j++) 
            cnt[j] += dp[i - 1] * num[i];
        for(int j = 0; j < num[i]; j++)
            cnt[j] += ten[i - 1];
        ll num2 = 0;
        for(int j = i - 1; j >= 1; j--)
            num2 = num2 * 10 + num[j];
        cnt[num[i]] += num2 + 1;
        cnt[0] -= ten[i - 1]; //判断前导0
    }
}
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(nullptr);
    init();
    ll a, b;
    cin >> a >> b;
    solve(a - 1,cnta), solve(b, cntb);
    for(int i = 0; i < 10; i++)
        cout << cntb[i] - cnta[i] << ' ';

    system("pause");
    return 0;
    
}