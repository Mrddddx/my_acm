#include<bits/stdc++.h>
using namespace std;
int a[200100];
struct st
{
    int x, y;
} ans[200100];
int t;
int main()
{
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        if(a[i] != i) t++, ans[t].x = a[i], ans[t].y = a[a[i]], x = a[i], y = a[a[i]], a[i] = y, a[a[i]] = x, i--;
    }
    cout << t << endl;
    for(int i = 1; i <=t; i++)
    {
        cout << ans[i].y << ' ' << ans[i].x << endl;
    }
    system("pause");
    return 0;
}