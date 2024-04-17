#include<bits/stdc++.h>

typedef long long ll;
const int N = 15;
ll dp[N][N];
ll cnta[N], cntb[N]; // cnt 统计
int num[N], now;

ll dfs(int pos, int sum, bool lead, bool limit) //pos表示当前处理的位数
{
    ll ans = 0;
    if(pos == 0) return sum;
    if(!lead && !limit && dp[pos][sum]!= -1) return dp[pos][sum]; //记忆化
    int up = (limit ? num[pos] : 9); //这一位的最大值
    for(int i = 0; i <= up; i++)
        if(i == 0 && lead) ans +=dfs(pos - 1, sum, 1, limit & i == up);
        else if(i == now) ans += dfs(pos - 1, sum + 1, 0, limit & i == up);
        else if(i != now) ans += dfs(pos - 1, sum, 0, limit & i == up);
    if(!lead && !limit) dp[pos][sum] = ans;
    return ans;
}
ll solve(ll x)
{
    int len = 0;
    while(x)
    {
        num[++len] = x % 10; //统计位数
        x = x / 10;
    }
    memset(dp, -1 ,sizeof dp);
    return dfs(len, 0, 1, 1);
}
int main()
{
    //std::ios::sync_with_stdio(0);
    //std::cin.tie(nullptr);
    ll a, b;
    std::cin >> a >> b;
    for(int i = 0; i < 10; i++)
        now = i, std::cout << solve(b) - solve(a - 1) << ' ';

    system("pause");
    return 0;
    
}