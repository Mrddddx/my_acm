#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll all;//棋盘格子总数
const int N = 1e6+6;
ll lines[N], rows[N];
ll n, k;
ll szl,szr;
ll ans;
int main()
{
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> lines[i] >> rows[i];  
    sort(lines + 1, lines + 1 + k);
    sort(rows + 1, rows + 1 + k);
    for(int i = 1; i <= k; i++)
    {
        if(lines[i] != lines[i-1]) szl ++;
        if(rows[i] != rows[i-1]) szr ++;
    }
    ans = szl * n + szr * n - szl * szr;
    cout << ans;
    system("pause");
    return 0;
}