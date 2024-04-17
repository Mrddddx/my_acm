#include <bits/stdc++.h> 
using namespace std;
const int N = 151515;
struct st{
    int x, y;
    int food;
} a[3030300];
int n;
int maxn;
int f[3030300];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        cin >> a[k].y ;
        a[k].food = a[k].y - k + 1;
        maxn = max (maxn , a[k].y);
    }
    for(int i = maxn ;i >= 0; i--)
    {
        if(a[i].food) 
            f[i] = max (f[i + 1] , f[a[i].y + 1] + a[i].food);
        else
            f[i] = f[i + 1]; 
    }
    /*检查： 动态规划的每一个点的数据
    for(int i = 1; i <= maxn; i++)
        cout<<f[i]<<' ';
    */
    cout << f[1];
    system("pause");
    return 0;
}