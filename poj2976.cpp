#include <cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n, k;
struct Pair{
    int a, b;
    double y;
} p[1005];
bool cmp(Pair a, Pair b)
{
    return a.y > b.y;
}
bool check(double x)
{
    for(int i = 1; i <= n; i++)
        p[i].y = p[i].a * 1.0 - x * p[i].b;
    sort(p + 1, p + 1 + n, cmp);
    double f = 0;
    for (int i = 1; i <= k; i++) f += p[i].y;
    return f < 0;
}


int main()
{
    while(cin >> n >> k && k + n)
    {
        k = n - k;
        for (int i = 1; i <= n; i++) cin >> p[i].a;
        for (int i = 1; i <= n; i++) cin >> p[i].b;
        double L = 0, R = 0;
        for (int i = 1; i <= n; i++) R += p[i].a;
        for (int i = 1; i <= 50; i++) 
        {
            double mid = L + (R - L) / 2;
            if(check(mid)) R = mid;
            else L = mid;
        }
        int ans = (int)(100 * (L + 0.005));
        cout << ans << endl;
    }
    return 0;
}