#include <bits/stdc++.h>
using namespace std;

int blk, wht;//黑棋白棋数量
int k;

struct st{
    int len; //长度
    int black; //拥有黑棋数量
} a[100861];
int ans;
int main()
{
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i].len >> a[i].black;
        blk = max(blk, a[i].black);
        wht = max(wht, a[i].len - a[i].black);
    }
    ans = blk + wht;
    cout << ans << endl;
    for (int i = 1; i <= blk; i++) cout << 1;
    for (int i = 1; i <= wht; i++) cout << 0;
    for(int i = 1; i <= k; i++)
    {
        cout << endl << blk - a[i].black;
    }

    system("pause");
    return 0;
}