#include <bits/stdc++.h> 
using namespace std;
int t;//到达时间
int n;
int i;//难解释
int i2;
int k;//每条船上的人数
int b[303030];//国家
int w[303030];//第i个人到的时间
int x[303030];//第i个人到的国家
int ans;
int main()
{
    int n;
    cin >> n;
    for (int j = 1; j <= n; j++)
    {
        cin >> t >> k;
        while (k--)
        {
            w[++i] = t;
            cin >> x[i];
            if (!b[x[i]]) ans++;
            b[x[i]]++;
        }
        while (t - w[i2] >= 86400)
            if (!--b[x[i2++]]) ans--;
        cout << ans << endl;
    }
    
    system("pause");
    return 0;
}