#include <bits/stdc++.h> 
using namespace std;
int ans = 100;
int n, m;

int malon[101];
long long  f[31][31][31]; //f[a][b][c]表示a个不拿b个拿c个拿一半的情况的最接近m, 开longlong 
int main()
{
    cin >> n >> m;
    m *= 2; //需要重量*2，每个瓜重量*2，这样就不用小数运算了
    for (int i = 1; i <= n; i++)
    {
        cin >> malon[i];
        malon[i] *= 2;
    }
    f[0][0][0] = 0;
    for (int a = 0;a <= n; a++)
        for (int b = 0;b <= n; b++)
            for (int c = 0;c <= n; c++)
            {
                if (a + b + c > n) continue;
                int nums = a + b + c; // 对第nums个瓜的选择
                if (a) f[a][b][c] = max (f[a][b][c] ,f[a - 1][b][c]);
                if (b && f[a][b - 1][c] + malon[nums] <= m) f[a][b][c] = max (f[a][b][c] ,f[a][b - 1][c] + malon[nums]);
                if (c && f[a][b][c - 1] + malon[nums]/2 <= m) f[a][b][c] = max (f[a][b][c] ,f[a][b][c - 1] + malon[nums]/2);
                if (f[a][b][c] == m) ans = min(ans , c);
                cout << a << b << c << ' ' << f[a][b][c]<<endl;
            }
    if (ans == 100) 
        cout << "-1";
    else 
        cout << ans ;
    system("pause");
    return 0;
}