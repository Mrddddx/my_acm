#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100]; //Fibonacci数列
int t;
int m;
void pre()
{
    f[1] = 1;
    f[2] = 2;
    t = 2;
    for(int i = 3; i <= 100; i++)
    {
        f[++t] = f[i - 2] + f[i - 1];
        if(f[i] > 1e12) {break;}
    }
}
ll find_fa(ll x)
{
    int L = 0, R = t;
    while(L < R)
    {
        int mid = L + R >> 1;
        if(f[mid] >= x) R = mid;
        else L = mid + 1;
    }
    return x - f[L - 1];
}
int main()
{
    pre(); 
    cin >> m;
    while(m--)
    {
        ll x, y;
        cin >> x >> y;
        //cout << find_fa(x) << ' ' << find_fa(y);
        while(x != y)
        {
            if(x > y) x = find_fa(x);
            else y = find_fa(y);
        }
        cout << x << endl;
    }
    system("pause");
    return 0;       
}